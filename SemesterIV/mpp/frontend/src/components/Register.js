import React from "react";
import { useState } from "react";
import { Link, useNavigate } from 'react-router-dom';
import { register, login } from '../services/login_service';
import axios from "axios";

const Register = () => {
    const [username, setUsername] = useState('');
    const [password, setPassword] = useState('');

    const register_button = async () => {
        const result = await register(username, password);
        if (result) {
            alert('Successfully registered');
            

        } else {
            alert('Failed to register');
        }

    };

    const navigate = useNavigate();

    
    const login_button = async () => {
        const result = await login(username, password);
        console.log(result);
        if (result) {
            alert('Successfully logged in');
            navigate('/bird');
        } else {
            alert('Failed to login');
        }
    };

    const handleInputName = (event) => {
        setUsername(event.target.value);
    };

    const handleInputPassword = (event) => {
        setPassword(event.target.value);
    };

    return (
        <div>
        <form>
            <label htmlFor="username">Username:</label>
            <input type="text" id="username" name="username" value={username} onChange={handleInputName} />
            <br />
            <label htmlFor="password">Password:</label>
            
            <input type="password" id="password" name="password" value={password} onChange={handleInputPassword}/>
            <br />
            <button type="dialog" onClick={register_button}>Register</button>
            <button type="dialog" onClick={login_button}>Login</button>
        </form>
        </div>
    );
    };

export default Register;