// Input array that has to be sorted
var n = [5,3,7,6,2,9];

// Swap Function
function swap(n, l, r){
    var temp = n[l];
    n[l] = n[r];
    n[r] = temp;
}

// Paritioning of array ,so that the elements can be sorted
function part(n, l, r) {
    var pivot   = n[Math.floor((r + l) / 2)], 
        i       = l,  j       = r; 
    while (i <= j) {
        while (n[i] < pivot) {
            i++;
        }
        while (n[j] > pivot) {
            j--;
        }
        if (i <= j) {
            swap(n, i, j); 
            i++;
            j--;
        }
    }
    return i;
}
 // Sorting function
function Sort(n, l, r) {
    var x;
    if (n.length > 1) {
        x = part(n, l, r); 
        if (l < x - 1) { 
            Sort(n, l, x - 1);
        }
        if (x < r) { 
            Sort(n, x, r);
        }
    }
    return n;
}
// 
var sortedArray = Sort(n, 0, n.length - 1);
console.log(sortedArray); 
