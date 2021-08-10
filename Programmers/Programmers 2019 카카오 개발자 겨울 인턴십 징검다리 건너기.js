//현재 사람의 수가 징검다리를 건널 수 있는지 체크
function check(stones, mid, k){
    let cnt = 0; //연속된 0의 갯수 세기
    for(let i = 0; i<stones.length; i++){
        //디딤돌의 숫자가 건너는 사람수보다 작으면 건너기전에 현재 디딤돌이 0이 되었다는 뜻
        if(parseInt(stones[i]) < mid){
            cnt++;
        }
        //건널 수 있으면 연속된 0의 갯수 다시 초기화
        else{
            cnt = 0;
        }
        //연속된 0의 갯수가 한번에 건널 수 있는 최대칸수와 같거나 크면 false 리턴(사람수 줄여야함)
        if(cnt >= k){
            return false;
        }
    }
    //아니면 true 리턴(사람수 늘려야함)
    return true;
}

function solution(stones, k) {
    let left = Number.MAX_VALUE
    let right = Number.MIN_VALUE
    //징검다리의 최솟값, 최댓값 저장
    for(let i=0; i<stones.length; i++){
        left = Math.min(parseInt(stones[i]), left)
        right = Math.max(parseInt(stones[i]), right)
    }
    while(left <= right){
        let mid = parseInt((left + right) / 2); //중간값 계산(건너는 사람)
        //건널수 없으면 사람 수 줄임
        if(!check(stones, mid, k)){
            right = mid-1;
        }
        //건널수 있으면 사람 수 늘림
        else{
            left = mid+1;
        }
    }
    return right;
}