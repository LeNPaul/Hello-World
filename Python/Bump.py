import pygame
import math
import random

#Initializing pygame and setting up the game screen

pygame.init()

white = (255, 255, 255)
black = (0, 0, 0)
red = (255, 0, 0)

displayWidth = 800
displayHeight = 600

clock = pygame.time.Clock()

gameDisplay = pygame.display.set_mode((displayWidth,displayHeight))
pygame.display.set_caption("Bump")
pygame.display.update()

gameExit = False

#Setting up initial functions and parameters

boxNumber = 1
boxes = []
particleNumber = 10
particles = []

gravity = (math.pi,0)
drag = 0.99
elasticity = 0.99

def addVectors((angle1, length1), (angle2, length2)):
    x = math.sin(angle1) * length1 + math.sin(angle2) * length2
    y = math.cos(angle1) * length1 + math.cos(angle2) * length2

    angle = 0.5 * math.pi - math.atan2(y, x)
    length = math.hypot(x, y)

    return(angle, length)

def findParticle(particles, x, y):
    for p in particles:
        if math.hypot(p.x - x, p.y - y) <= p.size:
            return p

def collide(p1, p2):
    dx = p1.x - p2.x
    dy = p1.y - p2.y

    distance = math.hypot(dx, dy)
    if distance < p1.size + p2.size:
        tangent = math.atan2(dy, dx)
        angle = 0.5 * math.pi + tangent

        angle1 = 2*tangent - p1.angle
        angle2 = 2*tangent - p2.angle
        speed1 = p2.speed*elasticity
        speed2 = p1.speed*elasticity

        (p1.angle, p1.speed) = (angle1, speed1)
        (p2.angle, p2.speed) = (angle2, speed2)

        p1.x += math.sin(angle)
        p1.y -= math.cos(angle)
        p2.x -= math.sin(angle)
        p2.y += math.cos(angle)

class Particle:
    def __init__(self, (x,y), size):
        self.size = size
        self.x = x
        self.y = y
        self.color = (random.uniform(0,255),random.uniform(0,255),random.uniform(0,255))
        self.thickness = 1
        self.speed = 0
        self.angle = 0

    def move(self):
        (self.angle, self.speed) = addVectors((self.angle, self.speed), gravity)
        self.x += math.sin(self.angle)*self.speed
        self.y -= math.cos(self.angle)*self.speed
        self.speed *= drag

    def bounce(self):
        if self.x > displayWidth - self.size:
            self.x = 2*(displayWidth - self. size) - self.x
            self.angle = - self.angle
            self.speed *= elasticity
        elif self.x < self.size:
            self.x = 2*self.size - self.x
            self.angle = - self.angle
            self.speed *= elasticity
        if self.y > displayHeight - self.size:
            self.y = 2*(displayHeight - self. size) - self.y
            self.angle = math.pi - self.angle
            self.speed *= elasticity
        elif self.y < self.size:
            self.y = 2*self.size - self.y
            self.angle = math.pi - self.angle
            self.speed *= elasticity

    def display(self):
        pygame.draw.circle(gameDisplay, self.color, (int(self.x), int(self.y)), self.size, self.thickness)

class Boxes(Particle):

    def display(self):
        pygame.draw.rect(gameDisplay, self.color, [int(self.x), int(self.y), self.size, self.size])

#Setting initital conditions of bubbles and rendering them

for n in range(particleNumber):
    size = random.randint(10,20)
    x = random.randint(size, displayWidth - size)
    y = random.randint(size, displayHeight - size)

    particle = Particle((x,y), size)
    particle.speed = random.random()*10
    particle.angle = random.uniform(0, math.pi*2)

    particles.append(particle)

#Setting initital conditions of boxes and rendering them

for n in range (boxNumber):
    size = random.randint(10,20)
    x = random.randint(size, displayWidth - size)
    y = random.randint(size, displayHeight - size)

    box = Boxes((x,y), size)
    box.speed = random.random()*10
    box.angle = random.uniform(0, math.pi*2)

    boxes.append(box)

selected_particle = None

#Main game loop

while not gameExit:
    for event in pygame.event.get():

        #Handling quit events

        if event.type == pygame.QUIT:
            gameExit = True

        #Handling user inputs

        if event.type == pygame.MOUSEBUTTONDOWN:
            (mouseX, mouseY) = pygame.mouse.get_pos()
            selected_particle = findParticle(particles, mouseX, mouseY)
        elif event.type == pygame.MOUSEBUTTONUP:
            selected_particle = None

    #Game Logic

    gameDisplay.fill(white)

    #Mouse controlled character

    if selected_particle:
        (mouseX, mouseY) = pygame.mouse.get_pos()
        dx = mouseX - selected_particle.x
        dy = mouseY - selected_particle.y
        selected_particle.angle = 0.5*math.pi + math.atan2(dy, dx)
        selected_particle.speed = math.hypot(dx, dy) * 0.1

    #Rendering the boxes

    for i, box in enumerate(boxes):
        box.move()
        box.bounce()
        for box2 in boxes[i+1:]:
            collide(box, box2)
        box.display()

    #Command controlling the bubbles

    for i, particle in enumerate(particles):
        particle.move()
        particle.bounce()
        for particle2 in particles[i+1:]:
            collide(particle, particle2)
            for i, box in enumerate(boxes):
                collide(box, particle)
                particle.display()

    pygame.display.update()

    clock.tick(30)

pygame.quit()
quit()
