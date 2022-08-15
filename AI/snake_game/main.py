import pygame
from pygame.locals import *
import time

class Game:
    def __init__(self):
        pygame.init()
        self.surfaceBGColor = [50, 168, 82]
        self.windowSize = [1000, 500]
        self.surface = pygame.display.set_mode(self.windowSize)
        self.surface.fill(self.surfaceBGColor)

        self.snake = Snake(self.surface, self.surfaceBGColor)
        self.snake.draw()

    def run(self):
        running = True
        while running:
            self.snake.move_snake()
            if self.snake.check_if_hit_wall(self.windowSize):
                running = False
                break
            for event in pygame.event.get():
                if event.type == KEYDOWN:
                    if event.key == K_ESCAPE:
                        running = False

                    if event.key == K_UP or event.key == K_DOWN or event.key == K_RIGHT or event.key == K_LEFT:
                        self.snake.change_direction(event.key)
                elif event.type == QUIT:
                    running = False


class Snake:
    def __init__(self, parent_screen, parent_screen_bgcolor):
        self.parent_screen = parent_screen
        self.parent_screen_bgcolor = parent_screen_bgcolor
        self.block = pygame.transform.scale(pygame.image.load("resources/block.jpeg"), (20, 20))
        self.blockCoordinates = [100, 100]
        self.moving_direction = [1, 0]
        self.moving_speed = 5
        self.pause_time = 0.1

    def draw(self):
        self.parent_screen.fill(self.parent_screen_bgcolor)
        self.parent_screen.blit(self.block, self.blockCoordinates)
        pygame.display.flip()

    def move_snake(self):
        time.sleep(self.pause_time)
        movement = [self.moving_direction[i] * self.moving_speed for i in range(len(self.moving_direction))]
        self.blockCoordinates = [self.blockCoordinates[i] + movement[i] for i in range(len(movement))]
        print(self.blockCoordinates)
        self.draw()

    def change_direction(self, key):
        if key == K_UP:
            self.moving_direction = [0, -1]
        if key == K_DOWN:
            self.moving_direction = [0, 1]
        if key == K_LEFT:
            self.moving_direction = [-1, 0]
        if key == K_RIGHT:
            self.moving_direction = [1, 0]

    def check_if_hit_wall(self, window_size):
        coordinates = self.blockCoordinates
        if coordinates[0]>= window_size[0] or coordinates[0] < 0:
            return True
        if coordinates[1]>= window_size[1] or coordinates[1] < 0:
            return True
        return False



if __name__  == "__main__":
    game = Game()
    game.run()