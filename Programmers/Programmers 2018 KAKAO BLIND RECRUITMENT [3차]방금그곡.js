function solution(m, musicinfos) {
    var answer = "(None)"; //기본값으로 None을 넣어놓음
    let time = 0;
    //기억한 멜로디에 #이 있으면 치환
    m = m.replace(/C#/gi, "c");
    m = m.replace(/D#/gi, "d");
    m = m.replace(/F#/gi, "f");
    m = m.replace(/G#/gi, "g");
    m = m.replace(/A#/gi, "a");
    //탐색 
    for(let i=0; i<musicinfos.length; i++){
        let temp = musicinfos[i].split(','); //,로 나눠서 저장
        //악보 정보에 #이 있으면 치환
        temp[3] = temp[3].replace(/C#/gi, "c");
        temp[3] = temp[3].replace(/D#/gi, "d");
        temp[3] = temp[3].replace(/F#/gi, "f");
        temp[3] = temp[3].replace(/G#/gi, "g");
        temp[3] = temp[3].replace(/A#/gi, "a");
        
        //시작 시간과 끝 시간을 각각 시와 분으로 나눠서 저장
        let start_hour = parseInt(temp[0].substring(0,2));
        let start_min = parseInt(temp[0].substring(3,5));
        let end_hour = parseInt(temp[1].substring(0,2));
        let end_min = parseInt(temp[1].substring(3,5));
        let l; //곡 길이 변수
        //시작 시간과 끝 시간의 시가 같으면
        if(start_hour === end_hour){
            l = end_min - start_min; //곡 길이는 분 - 분
        }
        //시작 시간과 끝 시간의 시가 다르면
        else{
            //끝나는 시간의 분이 시작 시간의 분보다 크거나 같으면
            if(end_min >= start_min){
                //곡 길이는 (분 - 분) + (시 - 시) -> (시 - 시)에서 나온 값에 60을 곱해서 더해줌(1시간은 60분이므로)
                l = (end_min - start_min) + (60 * (end_hour - start_hour));
            }
            //끝나는 시간의 분이 시작 시간의 분보다 작으면
            else{
                //시에서 60분을 가져와서 계산
                l = ((end_min + 60) - start_min) + (60 * ((end_hour - 1) - start_hour));
            }
        }
        //곡 길이를 악보 정보의 길이로 나눈 몫만큼 악보 정보를 반복, 나누고 남은 나머지 값까지 뒤에 붙여줌
        let total = temp[3].repeat(parseInt(l/temp[3].length)) + temp[3].substring(0,l%temp[3].length);
        //재생 정보에 기억한 멜로디가 포함되어 있다면
        if(total.includes(m)){
            //answer의 값이 None이 아니면
            if(answer !== "(None)"){
                //현재 곡 길이가 이전 곡 길이보다 더 길면
                if(time < l){
                    answer = temp[2]; //현재 음악 제목을 answer에 넣어줌
                    time = l; //현재 곡 길이를 저장
                }
            }
            //answer의 값이 None이면
            else{
                answer = temp[2]; //현재 음악 제목을 answer에 넣어줌
                time = l; //현재 곡 길이를 저장
            }
        }
    }
    
    return answer;
}