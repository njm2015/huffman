def swap(list, a, b):
	temp = list[a]
	list[a] = list[b]
	list[b] = temp

def sort(list, lo, hi):
	
	if(lo-hi >= 0):
		return

	pivot = hi
	wall = lo

	for x in xrange(lo,hi):
		if(list[x] <= list[pivot]):
			swap(list, wall, x)
			wall += 1

	swap(list, wall, pivot)

	sort(list, lo, wall-1)
	sort(list, wall+1, hi)


def rev_sort(list, lo, hi):

	if(lo-hi >= 0):
		return

	pivot = hi
	wall = lo

	for x in xrange(lo,hi):
		if(list[x] >= list[pivot]):
			swap(list, wall, x)
			wall += 1

	swap(list, wall, pivot)

	rev_sort(list, lo, wall-1)
	rev_sort(list, wall+1, hi)


list = [4,3,2,1,5,0,10,9,6,5,4]

sort(list, 0, len(list)-1)
print list

rev_sort(list, 0, len(list)-1)
print list