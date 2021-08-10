function tok(file){
    let end_head = 0; //헤더의 마지막 인덱스 저장
    let end_number = 0; //넘버의 마지막 인덱스 저장
    for(let i=0; i<file.length; i++){
        //현재 문자가 숫자이면
        if(!isNaN(parseInt(file[i]))){
            end_head = i; //현재 인덱스 저장 후 탈출
            break;
        }
    }
    //넘버의 시작 부터 다시 탐색
    for(let i=end_head; i<file.length; i++){
        //현재 문자가 숫자가 아니면
        if(isNaN(file[i])){
            end_number = i; //현재 인덱스 저장 후 탈출
            break;
        }
    }
    //넘버의 마지막 인덱스가 초기값 그대로이면
    if(end_number === 0){
        end_number = file.length; //넘버의 마지막 인덱스는 현재 문자열의 끝
    }
    let head = file.substring(0,end_head); //헤더 만들기
    let number = file.substring(end_head, end_number); //넘버 만들기
    //헤더의 문자열을 모두 소문자로 바꾸고 넘버는 형식을 숫자로 바꿔 리턴
    return [head.toLowerCase(), parseInt(number)]; 
} 

function solution(files) {
    //sort
    files.sort(function(a,b){
        let s1 = tok(a);
        let s2 = tok(b);
        //헤더 비교 후 오름차순 정렬
        if(s1[0] < s2[0]){
            return -1;
        }
        else if(s1[0] > s2[0]){
            return 1;
        }
        //헤더가 같으면 넘버로 오름차순 정렬
        else{
            return s1[1] - s2[1];
        }
    })
    return files;
}