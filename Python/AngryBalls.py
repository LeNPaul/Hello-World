#render blocks
#render ball and get to fire (projectile motion)
#if ball hits block then block reacts
#cannon shoots cannon ball to knock over blocks

import pygame
import math

pygame.init()

white = (255,255,255)
black = (0,0,0)

displayWidth = 800
displayHeight = 600

clock = pygame.time.Clock()

gameDisplay = pygame.display.set_mode((displayWidth, displayHeight))
pygame.display.set_caption("Angry Balls")
pygame.display.update()

gameExit = False

#Setting up initial functions

def addVectors((angle1, length1), (angle2, length2)):
    x = math.sin(angle1) * length1 + math.sin(angle2) * length2
    y = math.cos(angle1) * length1 + math.cos(angle2) * length2

    angle = 0.5 * math.pi - math.atan2(y, x)
    length = math.hypot(x, y)

    return(angle, length)

#Main game loop

while not gameExit:
    for event in pygame.event.get():

        #Handling quit events

        if event.type == pygame.QUIT:
            gameExit = True

    gameDisplay.fill(white)



    pygame.display.update()

pygame.quit()
quit()
