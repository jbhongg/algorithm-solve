function solution(expression) {
    //우선순위 저장
    const arr = [
        ['+', '-', '*'],
        ['+', '*', '-'],
        ['-', '+', '*'],
        ['-', '*', '+'],
        ['*', '+', '-'],
        ['*', '-', '+']
    ];
    let answer = "";
    for (let ops of arr) {
        let temp = expression.split(/(\D)/) //숫자가 들어 있지 않은 것으로 나누기, 하지만 구분자도 배열에 포함시킴
        for (let op of ops) {
            //연산자가 수식에 포함되어 있으면
            while (temp.includes(op)) {
                //연산자의 위치를 저장
                let idx = temp.indexOf(op)
                //연산자와 앞뒤의 수를 잘라서 저장 
                let s = temp.slice(idx - 1, idx + 2)
                //계산하기 위해 자른 배열 합치기
                let formula = s.join("")
                let cal = eval(formula) //계산
                //배열에 계산한 값을 현재 연산자 앞에 넣고 계산에 사용한 수와 연산자(총 3개) 삭제
                temp.splice(idx - 1, 3, cal)
            }
        }
        //계산값을 절댓값으로 바꾼후 최댓값 저장
        answer = Math.max(answer, Math.abs(temp[0]))
    }

    return answer;
}