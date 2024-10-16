import axios from 'axios';


function login(username, password) {
    return new Promise((resolve, reject) => {
        axios.post('https://mpp.ghnr.xyz/login/', {username: username, password: password})
            .then(response => {
                resolve(response.data);
            })
            .catch(error => {
                reject(error);
            });
    });
}

async function register(username, password) {
    try {
        const response = await axios.post('https://mpp.ghnr.xyz/register/', {username: username, password: password});
        const data = response.data;
        return data;
    } catch (error) {
        return [];
    }
}

export { login, register };

