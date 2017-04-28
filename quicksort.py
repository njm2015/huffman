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
		if(list[x] < list[pivot]):
			swap(list, lo, x)
			wall += 1

	swap(list, wall, pivot)

	print list
	#print "lo: %d" % (lo)
	#print "hi: %d" % (hi)
	#print "wall: %d" % (wall)

	print "calling sort(list, %d, %d)" % (lo, wall)
	sort(list, lo, wall-1)
	print "calling sort(list, %d, %d)" % (wall, hi)
	sort(list, wall+1, hi)



list = [4,3,2,1,5,0,10,9,6]
sort(list, 0, len(list)-1)
print list
