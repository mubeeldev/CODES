
        import { product1 } from "./js-product/grid1.js";
        import { product2 } from "./js-product/grid2.js";
        import{product3} from "./js-product/grid3.js";
        import {product4} from "./js-product/grid4.js";
        import { product5} from "./js-product/grid5.js";
        import { product6} from "./js-product/grid6.js";

        document.querySelector('form').addEventListener('submit', function(event) {
            event.preventDefault();
            const image = document.getElementById('image').value;
            const description = document.getElementById('description').value;
            const order = document.getElementById('order').value;

            if(image && description && order) {
                // Here you would typically send the data to your server
                // alert('Product added successfully!');
                // Clear the form

                document.getElementById('image').value = '';
                document.getElementById('description').value = '';
                document.getElementById('order').value = '';
            } else {
                alert('Please fill in all fields.');
            }
        });
