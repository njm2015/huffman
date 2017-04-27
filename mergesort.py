def sort(list, lo, hi):
	if(lo >= hi):
		return 

	sort(list, lo, floor((lo+hi)/2))
	sort(list, ceil((lo+hi)/2), hi)

	mid = (lo+hi)/2

	while(lo <= mid)
		if(list[lo] > list[hi])
			temp = list[lo]
			list[lo] = list[hi]
			list[hi] = temp
