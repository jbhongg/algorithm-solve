function solution(board) {
    var answer = Number.MAX_VALUE;
    const dc = [-1,0,1,0];
    const dr = [0,1,0,-1];
    const visit = Array.from(Array(25), () => Array(25).fill(0));
    class info { 
        constructor(c, r, dir, cost) { 
            this.c = c; 
            this.r = r;
            this.dir = dir;
            this.cost = cost;
        } 
    }
    let q = [];
    q.push(new info(0,0,-1,0));
    //bfs
    while(q.length !== 0){
        let temp = q[0];
        q.shift();
        let c = temp.c;
        let r = temp.r;
        let dir = temp.dir;
        let cost = temp.cost;
        //끝지점에 도착하면 비용 비교
        if(c === board.length-1 && r === board.length-1){
            answer = Math.min(answer, cost)
            continue;
        }
        //사방 탐색
        for(let i=0; i<4; i++){
            let nc = c + dc[i];
            let nr = r + dr[i];
            let ndir;
            let ncost = cost;
            //방향이 상하일경우
            if(i === 0 || i === 2){
                ndir = 1;
            }
            //방향이 좌우일 경우
            else{
                ndir = 2;
            }
            //탐색한 위치가 맵안에 있고 벽이 아니라면
            if(nc >=0 && nc < board.length && nr >= 0 && nr < board.length && board[nc][nr] !== 1){
                //현재 위치까지의 비용이 이전의 비용보다 적다면 다음 탐색
                if(visit[nc][nr] !== 0 && visit[nc][nr] < cost){
                    continue;
                }
                //아니면 현재 비용을 저장
                visit[nc][nr] = cost;
                //출발위치가 아니고 방향이 바뀌었다면
                if(dir !== -1 && dir !== ndir){
                    ncost = ncost + 500; //코너 비용 계산
                }
                ncost = ncost + 100; //직선 도로 비용 계산
                //현재까지의 비용이 저장되어 있는 비용보다 크거나 같으면 다음 탐색
                if(ncost >= answer){
                    continue;
                }
                //아니면 큐에 저장
                q.push(new info(nc, nr, ndir, ncost));
            }
        }
    }

    return answer;
}