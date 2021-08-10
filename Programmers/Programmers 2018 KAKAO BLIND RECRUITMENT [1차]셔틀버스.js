function solution(n, t, m, timetable) {
    let answer = '';
    let shuttle = ["09:00"]; //09:00부터 셔틀 시작
    timetable.sort(); //시간 순서대로 정렬
    //셔틀버스이 오는 시간을 배열로 만들어줌
    for(let i =1; i<n; i++){
        let hour = shuttle[i-1].substring(0,2); //이전 셔틀 버스 시간에서 시간만 자름
        let intHour = parseInt(hour); //int형으로 바꿔줌
        let minu = shuttle[i-1].substring(3,5); //이전 셔틀 버스 시간에서 분만 자름
        let intMinu = parseInt(minu); //int형으로 바꿔즘
        let sum = intMinu + t; //t분 후에 다음 셔틀이 오는 것이므로 t를 분에 더함
        //더한 분이 59를 넘으면
        if(sum >59){
            minu = sum % 60; //60으로 나눈 나머지 값만 분에 저장
            hour = intHour + parseInt(sum / 60); //60으로 나눈 몫을 시간에 더해줌
        }
        //더한 분이 59를 넘지 않으면
        else{
            minu = sum;  //분은 더한 분 그대로
            hour = intHour; //시간은 그대로
        }
        //분이 10 미만이면
        if(minu < 10){
            minu = "0" + minu; //앞에 0을 추가
        }
        //시간이 10미만이면
        if(hour < 10){
            hour = "0" + hour; //앞에 0을 추가
        }
        sum = hour + ":" + minu; //시간:분 형식으로 만들어줌
        shuttle[i] = sum; //배열에 저장
    }
    let idx = 0; //다음 탐색할 timetable의 idx 값을 저장
    //셔틀 버스에 크루 넣기
    for(let i=0; i<shuttle.length; i++){
        let count = 0; //탑승한 크루 수 세기 위한 변수
        for(let j = idx; j<timetable.length; j++){
            //셔틀 버스 시간보다 크루 시간이 작거나 같으면
            if(shuttle[i] >= timetable[j]){
                count++;   //현재 셔틀에 크루 탑승 했으므로 수 증가
                idx = j+1; //다음 탐색할 idx 값 저장
                //탑승한 크루 값이 정원이라면 탈출
                if(count === m){
                    break;
                }
            }
            //셔틀 버스 시간보다 크루 시간이 크면 탈출
            else{
                break;
            }
        }
        //정원이 아닌데 마지막 셔틀이면
        if(count !== m && i === shuttle.length-1){
            answer = shuttle[shuttle.length-1]; //답은 마지막 셔틀 시간
        }
        //정원인데 마지막 셔틀이면
        else if(count === m && i === shuttle.length-1){
            let hour =timetable[idx - 1].substring(0,2); //마지막으로 셔틀에 탑승한 크루의 시간에서 시간만 자름
            let intH = parseInt(hour); //int형으로 변환
            let minu = timetable[idx - 1].substring(3,5); //마지막으로 셔틀에 탑승한 크루의 시간에서 분만 자름
            let intM = parseInt(minu); //int형으로 변환
            let sum = "";
            minu = intM-1; //자른 분에 1을 빼줌
            //현재 분이 10미만이라면
            if(minu < 10){
                //현재 분이 0 미만이라면
                if(minu < 0){
                    minu = "59"; //분은 59
                    hour = intH - 1; //시간에 1을 빼줌
                    //시간이 10미만이라면
                    if(hour < 10){
                        hour = "0" + hour; //앞에 0을 추가
                    }
                }
                else{
                    minu = "0" + minu; //앞에 0을 추가
                }
            }
            sum = hour + ":" + minu; //시간:분 형식으로 만들어줌 이게 답
            answer = sum; //더이상 셔틀이 없는데 정원이라면 이 셔틀에 탄 마지막 사람보다 1분 빨리오는 것이 가장 늦게 탈 수 있는 시간이다.
        }
    }
    return answer;
}