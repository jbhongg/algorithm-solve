function solution(s) {
    var answer = [];
    let set = new Set();
    //입력 문자열 전처리
    let temp = s.replace("{{","").replace("}}","").split("},{");
    //집합수가 작은 순으로 정렬
    temp.sort(function(a,b){
        return a.length - b.length
    });
    //순서대로 넣어줌
    for(let i=0; i<temp.length; i++){
        let a = temp[i].split(',');
        for(let j = 0; j<a.length; j++){
           set.add(parseInt(a[j]));
        }
    }
    answer = [...set];
    return answer;
}