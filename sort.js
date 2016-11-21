'use strict';

let list = [5,3,7,3,5,2,9,4,2,7];


function bubblesort(list){
  list = list.slice();
  for(let i = 0; i < list.length - 1; i++)
    for(let j = i + 1; j < list.length; j++)
      if(list[i] > list[j]){
        let tmp = list[i];
        list[i] = list[j];
        list[j] = tmp;
      }
  return list;
}

function mergesort(list, begin, end){
  if(typeof begin == "undefined") begin = 0;
  if(typeof end == "undefined") end = list.length;
  
}

function quicksort(list, begin, end){
  list = list.slice();
  if(typeof begin == "undefined") begin = 0;
  if(typeof end == "undefined") end = list.length;
  if(begin >= end) return;
  
  let i0 = begin + 1, i1 = end - 1, pivot = begin;
  
  while(i0 < i1){
    if(list[i0] > list[pivot]){
      if(list[i1] > list[pivot]){
        i1--; //both greater
      }else{ //out of order
        let tmp = list[i0];
        list[i0] = list[i1];
        list[i1] = tmp;
        i0 ++;
        i1 --;
      }
    }else{
      if(list[i1] > list[pivot]){ //in order
        i0++;
        i1--;
      }else{ //both less
        i0++;
      }
    }
  }
  
  let tmp = list[i0-1];
  list[i0-1] = list[pivot];
  list[pivot] = tmp;
  
  quicksort(list, begin, i0-1);
  quicksort(list, i0, end);
  
  return list;
}

console.log(list,bubblesort(list));
console.log(list,quicksort(list));
