function solve(nodeinfo, preorder, postorder, levels, level){
    let nodes = nodeinfo.slice();
    let node = nodes.shift(); //현재 노드
    preorder.push(parseInt(node[2])); //전위 순회 배열에 현재 노드 번호 추가
    //노드 탐색
    for(let n of nodes){
        //노드의 레벨이 현재 노드보다 레벨이 하나 높으면
        if(parseInt(n[1]) === levels[level+1]){
            //노드의 x축 값이 현재 노드의 값보다 작으면(parent노드보다 왼쪽에 있으면)
            if(parseInt(n[0]) < parseInt(node[0])){
                let arr = [];
                //parent노드보다 왼쪽에 있는 노드들 전부 배열에 저장
                for(let m of nodeinfo){
                    if(parseInt(m[0]) < parseInt(node[0])){
                        arr.push(m);
                    }
                }
                //그 배열을 가지고 재귀
                solve(arr, preorder, postorder, levels, level+1);               
            }
            //노드의 x축 값이 현재 노드의 값보다 크다면(parent노드보다 오른쪽에 있으면)
            else{
                let arr = [];
                //parent노드보다 오른쪽에 있는 노드들 전부 배열에 저장
                for(let m of nodeinfo){
                    if(parseInt(m[0]) > parseInt(node[0])){
                        arr.push(m);
                    }
                }
                //그 배열을 가지고 재귀
                solve(arr, preorder, postorder, levels, level+1);
            }
        }
    }
    postorder.push(node[2]); //후위 순회 배열에 현재 노드 번호 추가
    return [preorder, postorder];
}

function solution(nodeinfo) {
    var answer = [];
    var preorder = [];
    var postorder = [];
    var temp = new Set();
    let num = 1;
    //각 노드에 번호 매기기 및 y축(level) 저장
    for(let node of nodeinfo){
        node.push(num);
        temp.add(node[1]);
        num++
    }
    var levels = [...temp]; //y축을 중복을 제거하고 저장하기 위해 set을 사용했으므로 다시 배열로 바꿔줌
    //level 내림차순 정렬
    levels.sort(function(a,b){
        return parseInt(b) - parseInt(a);
    })
    //노드 y축 기준 내림차순 정렬 같으면 x축 기준 오름차순 정렬
    nodeinfo.sort(function(a,b){
        if(parseInt(b[1]) == parseInt(a[1])){
            return parseInt(a[0]) - parseInt(b[0]);
        }
        return parseInt(b[1]) - parseInt(a[1]);
    })
    answer = solve(nodeinfo, preorder, postorder, levels, 0);
    return answer;
}