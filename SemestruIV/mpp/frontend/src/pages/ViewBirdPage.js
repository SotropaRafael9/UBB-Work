import React from 'react';
import { useParams } from 'react-router-dom';
import { Link } from 'react-router-dom';
import {UpdateForm} from '../components/UpdateForm.js';
import { useState } from 'react';
import { updateData } from '../services/bird_service';


const ViewBirdPage = (params) =>{
    const { id } = useParams();
    const [isOpen, setIsOpen] = useState(false);

    const bird = params.birds.find(bird => bird.id === Number.parseInt(id) || bird.id === Number.parseInt(params.id));
    if (!bird)
        return <h2>Bird with id {id} not found</h2>;

    const toogleForm = () => {
        setIsOpen(!isOpen);
    }
    
    return (
        <main className='viewBirdPage'>
            <div>
                <h1 className='BirdSelected'>{bird.name}</h1>
                <Link to="/" className='Back'><b>Back to Birds</b></Link>
                <div>
                    <button className="EditButton" onClick={() => toogleForm()}>Edit</button>
                    <div>
                        {isOpen && <UpdateForm update={updateData} id={bird.id} name={bird.name} color={bird.color} speed={bird.speed}/>}
                    </div>
                </div>
            </div>
            <div className="ViewBird">
                <h2>Bird Details</h2>
                <div>Bird name :<b> {bird.name}</b></div>
                <div>Bird color :<b> {bird.color}</b></div>
                <div>Bird speed :<b> {bird.speed}</b></div>
            </div>
        </main>
    );
} 

export default ViewBirdPage;