import os

readmetxt = "Leetcode Solutions\n========\nThis repository contains code of some famous leetcode problems\n\n### LeetCode Algorithms\n\n| # | Title | Solution | Difficulty | Topic |\n|---| ----- | -------- | ---------- | ----- |\n"

base = 'algorithms/cpp/'
filestructure = list(os.walk(base))

# dirs contains a list of dictionaries of directories to their path. 
dirs = dict()
codes = dict()

crnt = 1
for dirr in filestructure[0][1]:
	# dirr is Easy, Medium, Hard
	for each in filestructure[crnt][1]:
		# each is topic name
		dirs[dirr+','+each] = base + dirr + '/' + each +'/'
		codes[dirr+','+each] = []
	
	crnt = crnt + len(filestructure[crnt][1]) + 1

# print(dirs)

for key in codes:
	structure = list(os.walk(dirs[key]))
	# print(structure)
	for each in structure:
		codes[key] = structure[0][2]

print()		
print(codes)
print()

f = open('README.md', 'w')
f.write(readmetxt)
f.close()

f = open('README.md', 'r')
print(f.read())

