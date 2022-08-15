import os
import pyautogui as commMedium
import time
from PIL import ImageGrab

os.system("wmctrl -a snakes")
origin = (600, 250)
box_side = 48.125
total_boxes = 16
game_region = (origin[0], origin[1], origin[0] + 16*box_side, origin[1] + 16*box_side)
running_time = 10
starting_time = time.time()

def capture_game_image():
    return ImageGrab.grab(game_region)

def game_over():
    capture1 = capture_game_image()
    time.sleep(0.2)
    capture2 = capture_game_image()
    if(capture1 != capture2):
        return True
    return False

def start_game():
    commMedium.press('space')

def clickOnScreen(a, b):
    commMedium.click(origin[0] + a, origin[1] + b)

# http://www.snakes-and-apples.org/