t = int(input())
for case in range(1,t+1):
    n = int(input())
    timeslots = [[int(j) for j in input().strip().split(" ")] for i in range(n)]
    startingTime = [timeslots[i][0] for i in range(n)]
    sortedAccordingToStartTime = sorted(timeslots,key=lambda x: x[0])

    slot = [index for index, value in sorted(enumerate(startingTime), key=lambda x: x[1])]

    result = ['a' for i in range(n)]
    flag = 0
    C = {'start':0, 'end':0}
    J = {'start':0, 'end':0}

    for i in range(n):
        if (C['end'] <= sortedAccordingToStartTime[i][0]):
            C['start'] = sortedAccordingToStartTime[i][0]
            C['end'] = sortedAccordingToStartTime[i][1]
            result[slot[i]] = 'C'
        elif (J['end'] <= sortedAccordingToStartTime[i][0]):
            J['start'] = sortedAccordingToStartTime[i][0]
            J['end'] = sortedAccordingToStartTime[i][1]
            result[slot[i]] = 'J'
        else:
            flag = 1
            break
    
    if (flag == 1):
        print("Case #{0}: IMPOSSIBLE".format(case))
    else:
        print("Case #{0}: {1}".format(case,"".join(result)))