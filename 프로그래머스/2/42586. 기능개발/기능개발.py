def solution(progresses, speeds):
    answer = []
    index_for_progress = 0
    
    while index_for_progress < len(progresses):
        # 모든 작업에 대해 하루가 지날 때마다 작업 진도 업데이트
        for i in range(len(progresses)):
            if progresses[i] < 100:
                progresses[i] += speeds[i]
        
        # 배포 가능한 작업의 수 계산
        count = 0
        while index_for_progress < len(progresses) and progresses[index_for_progress] >= 100:
            count += 1
            index_for_progress += 1
        
        # 배포가 가능한 작업이 있을 경우 answer 배열에 추가
        if count > 0:
            answer.append(count)
    
    return answer
