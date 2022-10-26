// Implementation of Segmenyt Tree in JS 
    
function build(arr) 
{ 
        
    for (let i = 0; i < n; i++) 
        tree[n + i] = arr[i];
  
    for (let i = n - 1; i > 0; --i) 
        tree[i] = tree[i << 1] +
                   tree[i << 1 | 1]; 
}
    
function updateTreeNode(p, value) 
{ 
    tree[p + n] = value;
    p = p + n;
        
    for (let i = p; i > 1; i >>= 1)
        tree[i >> 1] = tree[i] + tree[i^1];
}

function query(l, r) 
{ 
    let res = 0;
        
    for (l += n, r += n; l < r;
                         l >>= 1, r >>= 1)
    {
        if ((l & 1) > 0) 
            res += tree[l++];
        
        if ((r & 1) > 0) 
            res += tree[--r];
    }
        
    return res;
}
  
let N = 100000;    
let n; 
let tree = new Array(2 * N);
tree.fill(0);

let a = [5,3,7,2,9,5,4];
    
n = a.length;

build(a);

console.log(query(1, 3)); 

// Input array = [5,3,7,2,9,5,4]

// Output -> Sum of numbers in range [1,3] -> 5+3+7 -> 10