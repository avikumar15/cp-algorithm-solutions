import os

base_leetcode = 'algorithms/leetcode/cpp/'
base_codejam = 'algorithms/google/'

filestructure_leetcode = list(os.walk(base_leetcode))
filestructure_codejam = list(os.walk(base_codejam))

# dirs contains a dictionary of directories to their path. 
dirs_leetcode = dict()
dirs_codejam = dict()

# codes contain a dictionary of difficulty, topic to the path of file.
codes_leetcode = dict()
codes_codejam = dict()

crnt = 1
for dirr in filestructure_leetcode[0][1]:
	# dirr is Easy, Medium, Hard
	for each in filestructure_leetcode[crnt][1]:
		# each refers to a topic name
		dirs_leetcode[dirr+','+each] = base_leetcode + dirr + '/' + each +'/'
		codes_leetcode[dirr+','+each] = []
	
	crnt = crnt + len(filestructure_leetcode[crnt][1]) + 1

crnt = 1
for dirr in filestructure_codejam[0][1]:
	# dirr is Directory in codejam folder
	for each in filestructure_codejam[crnt][1]:
		# each refers to a topic name
		dirs_codejam[dirr+','+each] = base_codejam + dirr + '/' + each +'/'
		codes_codejam[dirr+','+each] = []
	
	crnt = crnt + len(filestructure_codejam[crnt][1]) + 1

# print(dirs_leetcode)
# print(dirs_codejam)
# print(codes_leetcode)
# print(codes_codejam)

for key in codes_leetcode:
	structure = list(os.walk(dirs_leetcode[key]))
	path = []
	for each in structure[0][2]:
		path += [dirs_leetcode[key]+each]
	codes_leetcode[key] = path

for key in codes_codejam:
	structure = list(os.walk(dirs_codejam[key]))
	path = []
	for each in structure[0][2]:
		path += [dirs_codejam[key]+each]
	codes_codejam[key] = path

# print(codes_leetcode)
# print(codes_codejam)

# base readme text
readmetxt = "CP & Algorithm Solutions\n========\nThis repository contains code of cp and algorithmic problems from online coding problems\n\n### LeetCode Algorithms\n\n| # | Title | Solution | Difficulty | Topic |\n|---| ----- | -------- | ---------- | ----- |\n"

num = 1
for key in codes_leetcode:
	for filename in codes_leetcode[key]:
		f2 = open(filename, 'r')
		link = f2.readline().split()[-1]
		print(link)
		readmetxt += '|' + str(num) + '|[' + filename.split('/')[-1].split('.')[0] + '](' + link + ') | [C++](./' + filename + ')|' + filename.split('/')[2] + '|' + filename.split('/')[3] + '\n'
		num = num + 1

readmetxt += "\n\n### Google Contest Solutions\n\n| # | Contest Name | Title | Solution |\n|---| ----- | -------- | ---------- |\n"

num = 1
for key in codes_codejam:
	for filename in codes_codejam[key]:
		f2 = open(filename, 'r')
		link = f2.readline().split()[-1]
		print(link)
		readmetxt += '|' + str(num) + '|' + filename.split('/')[2] + '|[' + filename.split('/')[-1].split('.')[0] + '](' + link + ') | [C++](./' + filename + ')' + '\n'
		num = num + 1

f = open('README.md', 'w')
f.write(readmetxt)
f.close()

print('Updated README.md:')
f = open('README.md', 'r')
print(f.read())
