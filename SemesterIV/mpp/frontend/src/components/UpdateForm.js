import React, { useState } from 'react';

export const UpdateForm = (params) => {
    const [id] = useState(params.id);
    const [name, setname] = useState(params.name);
    const [color, setcolor] = useState(params.color);
    const [speed, setspeed] = useState(params.speed);

    const handleInputName = (event) => {
        setname(event.target.value);
    };

    const handleInputColor = (event) => {
        setcolor(event.target.value);
    };

    const handleInputSpeed = (event) => { 
        setspeed(event.target.value);
    };
    

    const handleUpdate = () => {
        params.update({ id, name, color, speed });
        
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
                <button type="button" className="button add" onClick={() =>handleUpdate() }>Update</button>

            </div>
        </form>
        
    );
};

export default UpdateForm;