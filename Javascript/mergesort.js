// Merge Sort Algorithm in Javascript 

function mergeSortRec(arr){
    
    const length = arr.length;
    
    if(length === 1){
      return arr;
    }
    
    const mid = Math.floor(length / 2);
   
    const left = arr.slice(0, mid);
  
    const right = arr.slice(mid, length);
    
    return merge(mergeSortRec(left), mergeSortRec(right));
  }
  
  function merge(leftArr, rightArr){
    
    const result = [];
    
    let iL = 0; 
    let iR = 0; 
    
   
    while(iL < leftArr.length && iR < rightArr.length){
      if(leftArr[iL] < rightArr[iR]){
        result.push(leftArr[iL]);
        iL++;
      }else{
        result.push(rightArr[iR]);
        iR++;
      }
    }
    
  
    while(iL < leftArr.length){
      result.push(leftArr[iL]);
      iL++;
    }
    
   
    while(iR < rightArr.length){
      result.push(rightArr[iR]);
      iR++;
    }
    
    return result;
  }

var arr = [3, 2, 10, 140, 5, 0 , 100, 38];
var result = mergeSortRec(arr);
console.log(result);

// Output
// [
//     0,  2,   3,   5,
//    10, 38, 100, 140
//  ]