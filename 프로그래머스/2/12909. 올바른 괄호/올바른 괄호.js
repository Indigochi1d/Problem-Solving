function solution(s) {
    let count = 0;

    for (let i = 0; i < s.length; i++) {
        if (s[i] === '(') {
            count++;
        } else if (s[i] === ')') {
            count--;
            // 만약 count가 음수가 되면 짝이 맞지 않는 것이므로 false 반환
            if (count < 0) return false;
        }
    }
    // 최종 count가 0이면 짝이 맞음
    return count === 0;
}
