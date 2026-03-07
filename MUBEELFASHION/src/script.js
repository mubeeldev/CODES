import { products1 } from '../js-product/grid1.js';
import { product2 } from '../js-product/grid2.js';
import { product3 } from '../js-product/grid3.js';
import { product4 } from '../js-product/grid4.js';
import { product5 } from '../js-product/grid5.js';
import { products6 } from '../js-product/grid6.js'; 
import { gridLayout } from '../src/function.js';


let grid1 = document.querySelector('.product-cont');
let grid2 = document.querySelector('.product-cont2');
let grid3 = document.querySelector('.product-cont3');
let grid4 = document.querySelector('.product-cont4');
let grid5 = document.querySelector('.product-cont5');
let grid6 = document.querySelector('.product-cont6');


gridLayout(products1, grid1);
gridLayout(product2, grid2);
gridLayout(product3, grid3);
gridLayout(product4, grid4);
gridLayout(product5, grid5);
gridLayout(products6, grid6);



