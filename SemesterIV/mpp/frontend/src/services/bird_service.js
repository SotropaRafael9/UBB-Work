import axios from 'axios';
//https://mpp.ghnr.xyz
async function fetchData() {
    try {
        const response = await axios.get('https://mpp.ghnr.xyz');
        const data = response.data;
        return data;
    } catch (error) {
        return [];  
    }
}

export async function get_birds_paginated(page, page_size) {
    try {
        const response = await axios.get(`https://mpp.ghnr.xyz/birds_paginated/?page=${page}&page_size=${page_size}`);
        const data = response.data;
        console.log("Datapaginated",response)
        return data;
    } catch (error) {
        return [];  
    }
}



export async function get_birds_count(){
    try {
        const response = await axios.get('https://mpp.ghnr.xyz/birds_count/');
        const data = response.data;
        return data.count;

    } catch (error) {
        return 0;  
    }
}

async function postData(bird) { 
    try {
        await axios.post('https://mpp.ghnr.xyz/birds_create/', bird );
        // Process the data here
    } catch (error) {
        // Handle the error here
    }
}

async function deleteData(id) {
    try {
        await axios.delete(`https://mpp.ghnr.xyz/birds_delete/${id}/`);
        
        // Process the data here
    } catch (error) {
        // Handle the error here
    }
}

async function updateData(bird) {
    try {
        await axios.put(`https://mpp.ghnr.xyz/birds_update/${bird.id}/`, bird);
        
        // Process the data here
    } catch (error) {
        // Handle the error here
    }
}
async function sortBirds1(){
    try {
        const response = await axios.get('https://mpp.ghnr.xyz/birds_sort/');
        const data = response.data;
        return data;
    } catch (error) {
        return [];  
    }
}


export async function filterBirds1(color) {
    try {
        const response = await axios.get(`https://mpp.ghnr.xyz/birds_filter/?color=${color}`);
        const data = response.data;
        console.log("data",response)
        return data;
    } catch (error) {
        return [];  
    }
}
async function piechart_bird(){
    try {
        const response = await axios.get('https://mpp.ghnr.xyz/birds_piechart/');
        const data = response.data;
        return data;
    } catch (error) {
        return [];  
    }
}

export { fetchData, postData, deleteData,updateData , sortBirds1, piechart_bird};
