import pygame
from pygame.locals import *
import time
import random
from pygame import mixer

class Game:
    def __init__(self):
        pygame.init()
        mixer.init()

        self.font = pygame.font.Font('freesansbold.ttf', 32)
        self.surfaceBGColor = [50, 168, 82]
        self.block_size = 20
        self.running = True
        self.windowSize = [50 * self.block_size, 25 * self.block_size]
        self.surface = pygame.display.set_mode(self.windowSize)
        self.surface.fill(self.surfaceBGColor)
        self.snake = Snake(self.surface, self.surfaceBGColor, self.windowSize, self.block_size, self.font)

    def game_over(self):
        mixer.music.load('resources/crash.mp3')
        mixer.music.play(loops = 0)

        game_over_text = self.font.render('Game over', True, (0, 0, 0))
        game_over_textRect = game_over_text.get_rect()
        game_over_textRect.center = (self.windowSize[0]/2, self.windowSize[1]/2)
        self.surface.blit(game_over_text, game_over_textRect)

        play_again_text = self.font.render('Press Space To Play Again', True, (0, 0, 0))
        play_again_textRect = play_again_text.get_rect()
        play_again_textRect.center = (self.windowSize[0]/2, self.windowSize[1]/2 + 30)
        self.surface.blit(play_again_text, play_again_textRect)
        pygame.display.flip()
        while self.running:
            for event in pygame.event.get():
                if event.type == KEYDOWN:
                    if event.key == K_ESCAPE:
                        self.running = False
                    if event.key == K_SPACE:
                        self.game_reset()
                        break
                elif event.type == QUIT:
                    self.running = False

    def game_reset(self):
        mixer.music.load('resources/background_music.mp3')
        mixer.music.set_volume(0.5)
        mixer.music.play()

        self.surface.fill(self.surfaceBGColor)
        self.snake = Snake(self.surface, self.surfaceBGColor, self.windowSize, self.block_size, self.font)
        self.run()

    def run(self):
        mixer.music.load('resources/background_music.mp3')
        mixer.music.set_volume(0.5)
        mixer.music.play()
        self.running = True
        self.paused = False
        while self.running and not self.snake.dead:
            if not self.paused:
                self.snake.move_snake()
            self.snake.display_score()
            for event in pygame.event.get():
                if event.type == KEYDOWN:
                    if event.key == K_ESCAPE:
                        self.running = False

                    # if event.key == K_PAUSE:
                        # self.paused = True
                    # elif event.key == K_CONTINUE:
                        # self.paused = False

                    if not self.paused and not self.snake.dead or event.key == K_UP or event.key == K_DOWN or event.key == K_RIGHT or event.key == K_LEFT:
                        self.snake.change_direction(event.key)
                elif event.type == QUIT:
                    self.running = False
        self.game_over()

class Snake:
    def __init__(self, parent_screen, parent_screen_bgcolor, parent_screen_size, block_size, font):
        self.font = font
        self.parent_screen = parent_screen
        self.parent_screen_bgcolor = parent_screen_bgcolor
        self.parent_screen_size = parent_screen_size
        self.block_size = block_size
        self.dead = False
        self.moving_direction = [1, 0]
        self.moving_speed = 1 * self.block_size
        self.pause_time = 0.2
        self.last_direction_change_time = 0

        self.body_block = pygame.transform.scale(pygame.image.load("resources/block.jpeg"), (self.block_size, self.block_size))
        self.body_coordinates = [[100-self.block_size, 100],[100, 100]]
        self.food_block = pygame.transform.scale(pygame.image.load("resources/apple.png"), (self.block_size, self.block_size))

        self.generate_food()
        for body_coordinate in self.body_coordinates:
            self.parent_screen.blit(self.body_block, body_coordinate)
        pygame.display.flip()

    def move_snake(self):
        time.sleep(self.pause_time)

        movement = [self.moving_direction[i] * self.moving_speed for i in range(len(self.moving_direction))]

        new_coordinate = [self.body_coordinates[-1][i] + movement[i] for i in range(len(movement))]
        if new_coordinate in self.body_coordinates or self.check_if_hit_wall(self.parent_screen_size):
            self.dead = True
            return

        self.body_coordinates.append(new_coordinate)
        self.parent_screen.blit(self.body_block, new_coordinate)

        if new_coordinate != self.food_coordinate:
            self.parent_screen.fill((self.parent_screen_bgcolor), (self.body_coordinates[0][0], self.body_coordinates[0][1], self.block_size, self.block_size))
            self.body_coordinates.pop(0)
        else:
            mixer.music.load('resources/powerup.mp3')
            mixer.music.play(loops = 0)
            self.generate_food()
            mixer.music.load('resources/background_music.mp3')
            mixer.music.set_volume(0.5)
            mixer.music.play()
        pygame.display.flip()

    def display_score(self):
        score_text = self.font.render("Score: " + str(len(self.body_coordinates)-2), True, (0, 0, 0))
        score_textRect = score_text.get_rect()
        score_textRect.center = (100, 50)
        self.parent_screen.fill(self.parent_screen_bgcolor, score_textRect)
        self.parent_screen.blit(score_text, score_textRect)
        pygame.display.flip()

    def generate_food(self):
        self.food_coordinate = [random.randint(0, (self.parent_screen_size[0]/self.block_size)-1)*self.block_size, random.randint(0, (self.parent_screen_size[1]/self.block_size)-1)*self.block_size]
        while self.food_coordinate in self.body_coordinates:
            self.food_coordinate = [random.randint(0, (self.parent_screen_size[0]/self.block_size)-1)*self.block_size, random.randint(0, (self.parent_screen_size[1]/self.block_size)-1)*self.block_size]
        self.parent_screen.blit(self.food_block, self.food_coordinate)

    def change_direction(self, key):
        if time.time() > self.last_direction_change_time + 0.1:
            if key == K_UP and self.moving_direction != [0, 1]:
                self.moving_direction = [0, -1]
                self.last_direction_change_time = time.time()
            if key == K_DOWN and self.moving_direction != [0, -1]:
                self.moving_direction = [0, 1]
                self.last_direction_change_time = time.time()
            if key == K_LEFT and self.moving_direction != [1, 0]:
                self.moving_direction = [-1, 0]
                self.last_direction_change_time = time.time()
            if key == K_RIGHT and self.moving_direction != [-1, 0]:
                self.moving_direction = [1, 0]
                self.last_direction_change_time = time.time()

    def check_if_hit_wall(self, window_size):
        coordinates = self.body_coordinates[-1]
        if coordinates[0]>= window_size[0] or coordinates[0] < 0:
            return True
        if coordinates[1]>= window_size[1] or coordinates[1] < 0:
            return True
        return False



if __name__  == "__main__":
    game = Game()
    game.run()