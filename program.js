
function waitfunction() {
  console.log("2");
  return new Promise(resolve => {
    setTimeout(() => {
      resolve("waitfun");
    }, 2000);
  });
}

// function clickHandler() {
//   console.log("click event handler...");
// }

// document.addEventListener("click", clickHandler);

async function x() {
  console.log("1");
  var a = await waitfunction();
  console.log(a);
  console.log("3");
  return "ss";
}

console.log(x());

// //waitfunction(); //a new context for this function is created and placed on the execution stack
// console.log("global context will be popped after this line");


// function asyncFunction1() {
//     setTimeout(function() {
//       console.log(1)
//     }, 1000)
//   }
  
//   function syncFunction1() {
//     console.log(2)
//   }
  
//   function syncFunction2() {
//     console.log(3)
//   }
  
//   asyncFunction1()
//   syncFunction1()
//   syncFunction2()

// function resolveAfter2Seconds(x) {
//     return new Promise(resolve => {
//       setTimeout(() => {
//         resolve(x+2);
//       }, 2000);
//     });
//   }
  
  // async function f1() {
  //   var x = await resolveAfter2Seconds(2);
  //   console.log(x); // 10
  // }
  
  // f1();