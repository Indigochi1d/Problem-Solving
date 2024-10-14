function solution(progresses, speeds) {
    let answer = [];
    let indexForProgress = 0;
    
    while (indexForProgress < progresses.length) {
        // 모든 작업에 대해 하루가 지날 때마다 작업 진도 업데이트
        for (let i = 0; i < progresses.length; i++) {
            if (progresses[i] < 100) {
                progresses[i] += speeds[i];
            }
        }

        // 배포 가능한 작업의 수 계산
        let count = 0;
        while (indexForProgress < progresses.length && progresses[indexForProgress] >= 100) {
            count+=1;
            indexForProgress+=1;
        }

        // 배포가 가능한 작업이 있을 경우 answer 배열에 추가
        if (count > 0) {
            answer.push(count);
        }
    }
    
    return answer;
}
