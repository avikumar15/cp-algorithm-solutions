import os

base = 'algorithms/cpp/'
filestructure = list(os.walk(base))

# dirs contains a dictionary of directories to their path. 
dirs = dict()
# codes contain a dictionary of difficulty, topic to the path of file.
codes = dict()

crnt = 1
for dirr in filestructure[0][1]:
	# dirr is Easy, Medium, Hard
	for each in filestructure[crnt][1]:
		# each refers to a topic name
		dirs[dirr+','+each] = base + dirr + '/' + each +'/'
		codes[dirr+','+each] = []
	
	crnt = crnt + len(filestructure[crnt][1]) + 1

# print(dirs)

for key in codes:
	structure = list(os.walk(dirs[key]))
	path = []
	for each in structure[0][2]:
		path += [dirs[key]+each]
	codes[key] = path

# print(codes)

# base readme text
readmetxt = "Leetcode Solutions\n========\nThis repository contains code of some famous leetcode problems\n\n### LeetCode Algorithms\n\n| # | Title | Solution | Difficulty | Topic |\n|---| ----- | -------- | ---------- | ----- |\n"

num = 1
for key in codes:
	for filename in codes[key]:
		f2 = open(filename, 'r')
		link = f2.readline().split()[-1]
		print(link)
		readmetxt += '|' + str(num) + '|[' + filename.split('/')[-1].split('.')[0] + '](' + link + ') | ![C++](./' + filename + ')|' + filename.split('/')[2] + '|' + filename.split('/')[3] + '\n'
		num = num + 1

f = open('README.md', 'w')
f.write(readmetxt)
f.close()

print('Updated README.md:')
f = open('README.md', 'r')
print(f.read())

