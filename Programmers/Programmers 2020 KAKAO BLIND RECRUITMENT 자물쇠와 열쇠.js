function rotate(key, temp, degree, s){
    let  k =0; //배열 인덱스
    //돌릴 각도가 0일때 그대로
    if(degree === 0){
        
    }
    //돌릴 각도가 90도 일 때
    else if(degree === 90){
        //위치에 맞게 키를 재배치
        for(let i=s-1; i>=0; i--){
            for(let j = 0; j<s; j++){
                key[j][i] = temp[k];
                k++;
            }
        }
    }
    //돌릴 각도가 180도 일 때
    else if(degree === 180){
        //위치에 맞게 키를 재배치
        for(let i=s-1; i>=0; i--){
            for(let j = s-1; j>=0; j--){
                key[i][j] = temp[k];
                k++;
            }
        }
    }
    //돌릴 각도가 270도 일 때
    else if(degree === 270){
        //위치에 맞게 키를 재배치
        for(let i=0; i<s; i++){
            for(let j = s-1; j>=0; j--){
                key[j][i] = temp[k];
                k++;
            }
        }
    }
}
function solution(key, lock) {
    var answer = false;
    let temp = [];
    let degree = 0;
    let count = 0;
    let ksize = key.length;
    let lsize = lock.length;
    
    //배열에 key를 순서대로 넣어줌
    for(let i =0; i<ksize; i++){
        for(let j = 0; j<ksize; j++){
            temp.push(key[i][j]);
        }
    }
    //자물쇠의 홈 세서 저장
    for(let i =0; i<lsize; i++){
        for(let j = 0; j<lsize; j++){
            if(lock[i][j] === 0){
                count++;
            }
        }
    }
    //자물쇠에 빈칸이 없으면 답은 true
    if(count === 0){
        answer = true;
    }
    //4번 돌림
    for(let k = 0; k<4; k++){
        //가능이면 탈출
        if(answer){
            break;
        }
        rotate(key, temp ,degree, ksize); //배열돌리기
        degree = degree + 90; //다음 각도
        //키의 맨 우측 하단을 자물쇠에 맨 좌측 상단에 맞춰서 시작, 키의 맨 좌측 상단이 자물쇠의 맨 우측 하단에 맞을 때까지 진행
        for(let i =1-ksize; i<lsize; i++){
            for(let j = 1-ksize; j<lsize; j++){
                let cnt = 0; //자물쇠 홈에 열쇠 돌기가 맞은 갯수 저장
                let flag = true; //false가 나왔을 때 반복문 탈출을 위한 변수
                let ii = 0; //key의 행
                for(let r = i; r<i+ksize; r++){
                    let jj = 0; //key의 열
                    for(let q = j; q<j+ksize; q++){
                        //맵을 벗어난 위치면 continue
                        if(r< 0 || q < 0 || r >= lsize || q >= lsize){
                            jj++; //key의 열 증가
                            continue;
                        }
                        //키와 자물쇠가 둘다 1이거나 0일때 탈출
                        if(lock[r][q]^key[ii][jj] === 0){
                            jj++; //key의 열 증가
                            flag = false; //불가능하다는 것을 표시
                            break;
                        }
                        //키가 1이고 자물쇠가 0이면
                        else if(lock[r][q] === 0 && key[ii][jj] === 1){
                            answer = true; //답을 true로 바꿔주고
                            cnt++; //갯수 증가
                        }
                        jj++; //key의 열 증가
                    }
                    ii++; //key의 행 증가
                    //불가능이면 반복문 탈출 다음 진행
                    if(!flag){
                        break;
                    }
                }
                //ture이고 현재 자물쇠 홈에 열쇠 돌기가 맞은 갯수가 자물쇠의 전체 홈 갯수와 같으면 반복문 탈출
                if(answer && cnt === count){        
                    break;
                }
                //ture이고 현재 자물쇠 홈에 열쇠 돌기가 맞은 갯수가 자물쇠의 전체 홈 갯수와 다르면 불가능으로 바꿔줌
                else if(answer && cnt !== count){
                    answer = false;
                }
            }
            //가능이면 탈출
            if(answer){
                break;
            }
        }
    }
    return answer;
}