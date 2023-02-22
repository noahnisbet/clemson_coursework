# Import the pygame module
import pygame
import os
import random
from itertools import permutations
import time

#from PIL import Image

# Import pygame.locals for easier access to key coordinates
# Updated to conform to flake8 and black standards
from pygame.locals import (
    K_UP,
    K_DOWN,
    K_LEFT,
    K_RIGHT,
    K_1,
    K_2,
    K_3,
    K_4,
	K_a,
	K_b,
	K_c,
	K_d,
	K_e,
	K_f,
	K_g,
	K_h,
	K_s,
	K_r,
	K_i,
	K_j,
	K_k,
	K_l,
	K_m,
    K_ESCAPE,
    KEYDOWN,
    QUIT,
)

def change_board():
	print("Enter state you want the board to be: (Ex: \"012345678\")")
	state = input()
	if len(state) != 9:
		print("invalid input")
		return

	state = str(state)

	values = ["0","1","2","3","4","5","6","7","8"]
	for char in state:
		if char not in values:
			print("invalid input")
			return
		values.remove(char)
	
	return state


def move_type(input,output):
	if move_up(input) == output:
		return "MOVE UP"
	if move_right(input) == output:
		return "MOVE RIGHT"
	if move_left(input) == output:
		return "MOVE LEFT"
	if move_down(input) == output:
		return "MOVE DOWN"

	return "invalid"

def print_directions():
	print()
	print("Artificial Intelligence Homework 1")
	print()
	print("Directions:")
	print("\t Click on the new python window named \"AI HW1\" and press keys to use.")
	print("\t Press Q in the window or the red X to end program.")
	print("\t Press UP or 1 to move blocks up")
	print("\t Press DOWN or 2 to move blocks down")
	print("\t Press LEFT or 3 to move blocks left")
	print("\t Press RIGHT or 4 to move blocks right")
	print("\t Press S to shuffle board")
	print()
	print("Parts:")
	print("\t Press A for part A (print all states)")
	print("\t Press B for part B (10 randomly selected states with no odd numbers)")
	print("\t Use directions above for part C")
	print("\t Press D for part D (All rows are divisible by 3)")
	print("\t Press E for part E (Breadth First Search)")
	print("\t Press F for part F (Depth First Search)")
	print("\t Press G for part G (Depth First Search 2)")
	print("\t Press H for part H1 (UCS with uniform cost)")
	print("\t Press I for part H2 (UCS with different costs)")
	print()
	print("Extra:")
	print("\t Press J for BFS on current state")
	print("\t Press K for DFS on current state")
	print("\t Press L for UCS on current state (with different costs)")
	print("\t Press M while on game then type state in terminal to change to specific state.")
	print()

def backtrace(parent, start, end):
    path = [end]
    while path[-1] != start:
        path.append(parent[path[-1]][0])
    path.reverse()

    count = 0
    print(f"The solution for this algorithm is {len(path)-1} moves long.")
    for i,p in enumerate(path):
        count+=1
        print(f"{count}: {print_out(p)}")
        if (i < len(path)-1):
            print(move_type(p,path[i+1]))
        print_out_pygame(p)
        print()
        time.sleep(0.25)

    return count


def part_b():
	odd = "1357"
	even = "02468"
	count = 0

	while (count < 10):
		odd = ''.join(random.sample(odd,len(odd)))
		even = ''.join(random.sample(even,len(even)))
		string = even[0] + odd[0] + even[1] + odd[1] + even[2] + odd[2] + even[3] + odd[3] + even[4]
		print(f"{count+1}: {print_out(string)}")	
		print_out_pygame(string)
		time.sleep(0.5)	
		count+=1


def part_d():
	count = 0
	while (count < 10):
		random_state = ''.join(random.sample(string,len(string)))
		if ((int(random_state[0:3]) % 3 == 0) and 
			(int(random_state[3:6]) % 3 == 0) and
			(int(random_state[6::]) % 3 == 0)):
			print(f"{count+1}: {print_out(random_state)}")	
			print_out_pygame(random_state)
			time.sleep(0.5)
			count += 1


def get_section(path, list_of_dims):
	# Setting the points for cropped image
	im = Image.open(str(os.getcwd())+path)
	im = im.resize((300,330))
	im = im.crop((list_of_dims[0], list_of_dims[1], list_of_dims[2], list_of_dims[3]))
	mode = im.mode
	data = im.tobytes()
	py_image = pygame.image.fromstring(data, im.size, mode).convert()
	return py_image

def print_all_states():
	ps = [''.join(p) for p in permutations("012345678")]
	for p in ps:
		print(p)
		print_out_pygame(p)

def print_out_pygame(string):
	position_map = {0:(0,0),
				1:(110,0),
				2:(220,0),
				3:(0,100),
				4:(110,100),
				5:(220,100),
				6:(0,200),
				7:(110,200),
				8:(220,200)}
	
	string_list = list(string)

	for i, char in enumerate(string_list):
		# create a surface object, image is drawn on it.
		imp = pygame.image.load(wd+f"/images/{char}.png").convert()
		screen.blit(imp, position_map[i])
		# Using blit to copy content from one surface to other
		#screen.blit(py_images[int(char)], position_map[i])
		screen_display.update()

def print_out(string):
    string = list(string)
    to_print = "\n"
    for i in range(9):
        if i % 3 == 0 and i != 0:
            to_print = to_print + '\n'
        to_print = to_print + string[i] + " "
    return to_print+"\n"

def move_up(string):
    string = list(string)
    zero_loc = string.index('0')
    if zero_loc in [0,1,2]:
        return ''.join(string)
    else:
        temp = string[zero_loc-3]
        string[zero_loc-3] = '0'
        string[zero_loc] = temp
        return ''.join(string)

def move_down(string):
    string = list(string)
    zero_loc = string.index('0')
    if zero_loc in [6,7,8]:
        return ''.join(string)
    else:
        temp = string[zero_loc+3]
        string[zero_loc+3] = '0'
        string[zero_loc] = temp
        return ''.join(string)

def move_left(string):
    string = list(string)
    zero_loc = string.index('0')
    if zero_loc in [0,3,6]:
        return ''.join(string)
    else:
        temp = string[zero_loc-1]
        string[zero_loc-1] = '0'
        string[zero_loc] = temp
        return ''.join(string)

def move_right(string):
    string = list(string)
    zero_loc = string.index('0')
    if zero_loc in [2,5,8]:
        return ''.join(string)
    else:
        temp = string[zero_loc+1]
        string[zero_loc+1] = '0'
        string[zero_loc] = temp
        return ''.join(string)

def move(string, movement):
	if movement == 1:
		return move_up(string)
	if movement == 2:
		return move_down(string)
	if movement == 3:
		return move_left(string)
	if movement == 4:
		return move_right(string)

def breadth_first_search(string, goal):
    open_list = []
    closed_list = []
    open_list.append(string)
    steps = -1
    graph = {}

    while len(open_list) != 0:
		
        curState = open_list.pop(0)
        steps += 1
        closed_list.append(curState)
        print_out_pygame(curState)
        
        if curState == goal:
            print("goal found in " + str(steps) + " steps")
            print()
            backtrace(graph,string,goal)
            return ""

        left = move_left(curState)
        right = move_right(curState)
        up = move_up(curState)
        down = move_down(curState)

        if (up not in open_list) and (up not in closed_list) and (up != curState):
            open_list.append(up)
            if up in graph:
                graph[up].append(curState)
            else:
                graph[up] = [curState]

        if (down not in open_list) and (down not in closed_list) and (down != curState):
            open_list.append(down)
            if down in graph:
                graph[down].append(curState)
            else:
                graph[down] = [curState]

        if (left not in open_list) and (left not in closed_list) and (left != curState):
            open_list.append(left)
            if left in graph:
                graph[left].append(curState)
            else:
                graph[left] = [curState]

        if (right not in open_list) and (right not in closed_list) and (right != curState):
            open_list.append(right)
            if right in graph:
                graph[right].append(curState)
            else:
                graph[right] = [curState]


def depth_first_search(string, goal):
    open_list = []
    closed_list = []
    open_list.append(string)
    steps = -1
    graph = {}

    while len(open_list) != 0:
		
        curState = open_list.pop(-1)
        steps += 1
        closed_list.append(curState)
        print_out_pygame(curState)
        
        if curState == goal:
            print("goal found in " + str(steps) + " steps")
            print()
            backtrace(graph,string,goal)
            return ""

        left = move_left(curState)
        right = move_right(curState)
        up = move_up(curState)
        down = move_down(curState)

        if (up not in open_list) and (up not in closed_list) and (up != curState):
            open_list.append(up)
            if up in graph:
                graph[up].append(curState)
            else:
                graph[up] = [curState]

        if (down not in open_list) and (down not in closed_list) and (down != curState):
            open_list.append(down)
            if down in graph:
                graph[down].append(curState)
            else:
                graph[down] = [curState]

        if (left not in open_list) and (left not in closed_list) and (left != curState):
            open_list.append(left)
            if left in graph:
                graph[left].append(curState)
            else:
                graph[left] = [curState]

        if (right not in open_list) and (right not in closed_list) and (right != curState):
            open_list.append(right)
            if right in graph:
                graph[right].append(curState)
            else:
                graph[right] = [curState]

def uniform_cost_search1(string, goal):
    open_list = {}
    closed_list = []
    open_list[0] = string
    steps = -1
    graph = {}
    cur_cost = 0

    while len(open_list.keys()) != 0:
        cur_cost = min(open_list.keys())
        curState = open_list.pop(min(open_list.keys()))
        steps += 1
        closed_list.append(curState)
        print_out_pygame(curState)

        if curState == goal:
            print("goal found in " + str(steps) + " steps")
            print()
            backtrace(graph,string,goal)
            return ""

		# cost = 1
        left = move_left(curState)
		# cost = 2
        right = move_right(curState)
		# cost = 1.5
        up = move_up(curState)
		# cost = 0.5
        down = move_down(curState)

        if (up not in open_list) and (up not in closed_list) and (up != curState):
            if (cur_cost+1) not in open_list:
                open_list[cur_cost+1] = up
            else:
                key = cur_cost+1
                while key in open_list:
                    key+=0.00001
                open_list[key] = up

            if up in graph:
                graph[up].append(curState)
            else:
                graph[up] = [curState]

        if (down not in open_list) and (down not in closed_list) and (down != curState):
            if (cur_cost+1) not in open_list:
                open_list[cur_cost+1] = down
            else:
                key = cur_cost+1
                while key in open_list:
                    key+=0.00001
                open_list[key] = down

            if down in graph:
                graph[down].append(curState)
            else:
                graph[down] = [curState]

        if (left not in open_list) and (left not in closed_list) and (left != curState):
            if (cur_cost+1) not in open_list:
                open_list[cur_cost+1] = left
            else:
                key = cur_cost+1
                while key in open_list:
                    key+=0.00001
                open_list[key] = left

            if left in graph:
                graph[left].append(curState)
            else:
                graph[left] = [curState]

        if (right not in open_list) and (right not in closed_list) and (right != curState):
            if (cur_cost+1) not in open_list:
                open_list[cur_cost+1] = right
            else:
                key = cur_cost+1
                while key in open_list:
                    key+=0.00001
                open_list[key] = right

            if right in graph:
                graph[right].append(curState)
            else:
                graph[right] = [curState]

def uniform_cost_search2(string, goal):
    open_list = {}
    closed_list = []
    open_list[0] = string
    steps = -1
    graph = {}
    cur_cost = 0

    while len(open_list.keys()) != 0:
        cur_cost = min(open_list.keys())
        curState = open_list.pop(min(open_list.keys()))
        steps += 1
        closed_list.append(curState)
        print_out_pygame(curState)

        if curState == goal:
            print("goal found in " + str(steps) + " steps")
            print()
            backtrace(graph,string,goal)
            return ""

		# cost = 1
        left = move_left(curState)
		# cost = 2
        right = move_right(curState)
		# cost = 1.5
        up = move_up(curState)
		# cost = 0.5
        down = move_down(curState)

        if (up not in open_list) and (up not in closed_list) and (up != curState):
            if (cur_cost+1.5) not in open_list:
                open_list[cur_cost+1.5] = up
            else:
                key = cur_cost+1.5
                while key in open_list:
                    key+=0.0001
                open_list[key] = up

            if up in graph:
                graph[up].append(curState)
            else:
                graph[up] = [curState]

        if (down not in open_list) and (down not in closed_list) and (down != curState):
            if (cur_cost+0.5) not in open_list:
                open_list[cur_cost+0.5] = down
            else:
                key = cur_cost+0.5
                while key in open_list:
                    key+=0.0001
                open_list[key] = down

            if down in graph:
                graph[down].append(curState)
            else:
                graph[down] = [curState]

        if (left not in open_list) and (left not in closed_list) and (left != curState):
            if (cur_cost+1) not in open_list:
                open_list[cur_cost+1] = left
            else:
                key = cur_cost+1
                while key in open_list:
                    key+=0.0001
                open_list[key] = left

            if left in graph:
                graph[left].append(curState)
            else:
                graph[left] = [curState]

        if (right not in open_list) and (right not in closed_list) and (right != curState):
            if (cur_cost+2) not in open_list:
                open_list[cur_cost+2] = right
            else:
                key = cur_cost+2
                while key in open_list:
                    key+=0.0001
                open_list[key] = right

            if right in graph:
                graph[right].append(curState)
            else:
                graph[right] = [curState]


if __name__ == "__main__":
	# Initialize pygame
	pygame.init()
	wd = os.getcwd()
	print_directions()

	# Define constants for the screen width and height
	SCREEN_WIDTH = 330
	SCREEN_HEIGHT = 300

	# Create the screen object
	# The size is determined by the constant SCREEN_WIDTH and SCREEN_HEIGHT
	screen = pygame.display.set_mode((SCREEN_WIDTH, SCREEN_HEIGHT))
	screen_display = pygame.display

	# set the pygame window name
	screen_display.set_caption('AI HW1')

	# Variable to keep the main loop running
	running = True
	string = "012345678"

	# Main loop
	while running:
		# Look at every event in the queue
		for event in pygame.event.get():
			# Did the user hit a key?
			if event.type == KEYDOWN:
				# Was it the Escape key? If so, stop the loop.
				if event.key == K_ESCAPE:
					running = False
				if event.key == K_UP:
					string = move(string,1)
				if event.key == K_DOWN:
					string = move(string,2)
				if event.key == K_LEFT:
					string = move(string,3)
				if event.key == K_RIGHT:
					string = move(string,4)
				if event.key == K_1:
					string = move(string,1)
				if event.key == K_2:
					string = move(string,2)
				if event.key == K_3:
					string = move(string,3)
				if event.key == K_4:
					string = move(string,4)

				if event.key == K_a:
					print_all_states()
					print_directions()

				if event.key == K_b:
					part_b()
					print_directions()

				if event.key == K_d:
					part_d()
					print_directions()

				if event.key == K_e:
					print(f"starting BFS on {325608147}...")
					print_out_pygame("325608147")
					time.sleep(1)
					breadth_first_search("325608147","012345678")
					print()
					string = "012345678"
					print_directions()

				if event.key == K_f:
					print(f"starting DFS on {325608147}...")
					print_out_pygame("325608147")
					time.sleep(1)
					depth_first_search("325608147","012345678")
					print()
					string = "012345678"
					print_directions()

				if event.key == K_g:
					print(f"starting DFS on {472103685}...")
					print_out_pygame("472103685")
					time.sleep(1)
					depth_first_search("472103685","123804765")
					print()
					string = "123804765"
					print_directions()

				if event.key == K_h:
					print(f"starting UCS...")
					uniform_cost_search1(string,"012345678")
					print()
					string = "012345678"
					print_directions()

				if event.key == K_i:
					print(f"starting UCS...")
					uniform_cost_search2(string,"012345678")
					print()
					string = "012345678"
					print_directions()

				if event.key == K_j:
					print(f"starting BFS...")
					breadth_first_search(string,"012345678")
					print()
					string = "012345678"
					print_directions()

				if event.key == K_k:
					print(f"starting DFS...")
					depth_first_search(string,"012345678")
					print()
					string = "012345678"
					print_directions()

				if event.key == K_l:
					print(f"starting UCS...")
					uniform_cost_search2(string,"012345678")
					print()
					string = "012345678"
					print_directions()

				if event.key == K_m:
					print()
					possible = change_board()
					if possible is not None:
						string = possible
					print_directions()

				if event.key == K_s:
					string = ''.join(random.sample(string,len(string)))

				if event.key == K_r:
					string = "012345678"

			# Did the user click the window close button? If so, stop the loop.
			elif event.type == QUIT:
				running = False

		print_out_pygame(string)
