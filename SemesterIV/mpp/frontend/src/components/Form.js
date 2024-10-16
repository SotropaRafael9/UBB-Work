import React, { useState } from 'react';

export const Form = ({ add, sortBirds,filterBirds}) => {
    const [name, setname] = useState('');
    const [color, setcolor] = useState('');
    const [speed, setspeed] = useState('');
    


    const handleInputName = (event) => {
        setname(event.target.value);
    };

    const handleInputColor = (event) => {
        setcolor(event.target.value);
    };

    const handleInputSpeed = (event) => { 
        setspeed(event.target.value);
    };
    

    const handleAdd = () => {
        add({ name, color, speed });
    
    };


    const handleSort = () => {
        sortBirds();
    };

    const handleFilter = () => {
        filterBirds(color);
    };
    return (
        <form className="bird-form">
  
            <div className="row">
            <label htmlFor="name-input"> <h2> Bird Name: </h2></label>
                <input id="name-input" type="text" value={name} onChange={handleInputName} />

            </div>
            <div className="row">
            <label htmlFor="color-input">
                <h2>Bird Color:</h2>
            </label>
                <input id="color-input" type="text" value={color} onChange={handleInputColor} />

            </div>
            
            <div className="row">
            <label htmlFor="speed-input">
                <h2>Bird Speed:</h2>
            </label>
                <input id="speed-input" type="text" value={speed} onChange={handleInputSpeed} />

            </div>
            <div className="buttons">
                <button type="button" className="button update" onClick={() =>handleAdd() }>Add</button>
                <button type="button" className="button sort" onClick={() =>handleSort() }>Sort</button>
                <button type="button" className="button filter" onClick={() =>handleFilter() }>Filter</button>
            </div>
        </form>
        
    );
};

export default Form;