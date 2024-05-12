import {Link} from 'react-router-dom';
import { React , useEffect, useState} from 'react';
import {Form} from '../components/Form.js';
import {PieChart} from 'react-minimal-pie-chart';
import './PageSelector.js';
import { filterBirds1, piechart_bird } from '../services/bird_service.js';
import PageSelector from './PageSelector.js';
import { postData, deleteData, updateData, sortBirds1, get_birds_paginated, get_birds_count } from '../services/bird_service.js';
import tree from './tree.png';

import {
    Chart as ChartJS,
    ArcElement,
    Tooltip,
    Legend
} from 'chart.js';

ChartJS.register(ArcElement, Tooltip, Legend);


const BirdPage = (params) => {

    const [isOpen] = useState(false);

    const [currentPage, setCurrentPage] = useState(0);
    const [BirdsPerPage, setBirdsPerPage] = useState(6);
    const [colors, setColors] = useState([]);
    const [totalCount, setTotalCount] = useState(0);



    useEffect(() => {
        async function PieChart() {
            const data = await piechart_bird()
            setColors(data)
        }
        PieChart().then();
    }, [])


    useEffect(() => {
        async function Pagination() {
            const newBirds = await get_birds_paginated(currentPage + 1, BirdsPerPage);
            params.setBirds(newBirds)
            const count = await get_birds_count();
            setTotalCount(count);
        }
        Pagination().then();
    }, [currentPage, BirdsPerPage, totalCount]) 
    
    
    
    const deleteBird = async (id) => {
        //params.setBirds(params.birds.filter(bird => bird.id !== id));
        await deleteData(id);   
    };

    

    const updateBird = async (updatedBird) => {
        // updatedBird.id = Number.parseInt(updatedBird.id);
        // const updatedBirds = params.birds.map(bird => (bird.id === updatedBird.id ? updatedBird : bird));
        // params.setBirds(updatedBirds);
        await updateData(updatedBird);
        window.location.reload();
    };

    const addBird = async (newBird) => {
        // const maxid = params.birds.reduce((max, bird) => bird.id > max ? bird.id : max, 0);
        // const newId = params.birds.length > 0 ? maxid + 1 : 1;
        // const newBird2  = { ...newBird, id: newId  };
        // params.setBirds(x => ([...x, newBird2]));
        await postData(newBird);
        window.location.reload();
    };


    const sortBirds = async() => {
        // const sortedBirds = params.birds.sort((a, b) => a.name.localeCompare(b.name));
        // params.setBirds(x => ([...sortedBirds]));
        const res = await sortBirds1();
        params.setBirds(res);
        //params.birds = await sortBirds1();
    };
    const filterBirds = async(color) => {
        // const filteredBirds = params.birds.filter(bird => bird.color === id);
        // params.setBirds(x => ([...filteredBirds]));
        const res = await filterBirds1(color);
        params.setBirds(res);
        console.log("dasdasdas",params.birds);

    };

    return <main className='BirdPage'> 
        
        <header className='title'>
            <h1 className="TitleBirds">BIRDS</h1>
            
        </header>
        <div className="main">
            
        <div className='left'>
            <div className="tree">
                <img src = {tree}/>
                <img className="reversed" src = {tree}/>
            </div>
        </div>
        <div className='center'>
            <div className='test'>

                <Form isOpen={isOpen} add={addBird} update={updateBird} sortBirds= {sortBirds} filterBirds = {filterBirds}/>
                <hr/>
                <div className="birds" data-testId = "Paginationn">
                    {
                        params.birds.map((bird, index) => (
                            <li key={index}>
                                { <Link to={`/bird/${bird.id}`}>{bird.name}</Link> }
                                <button onClick={() => deleteBird(bird.id)}><span className="button">Delete</span></button>
                            </li>
                        ))

                    }
                </div>
                { 
                    
                    <PageSelector offset = {currentPage} setOffset={setCurrentPage} totalItems={Math.floor(totalCount / BirdsPerPage)}
                    size ={Math.floor(totalCount / BirdsPerPage) + (totalCount % BirdsPerPage !== 0)}
                    />
                }
                <hr/>
                <div className='birdsPerPage'>
                    <label htmlFor="birdsPerPage">Birds per Page:</label>
                    <select id="birdsPerPage" value={BirdsPerPage} onChange={(e) => setBirdsPerPage(Number(e.target.value))}>
                        <option value={6}>6</option>
                        <option value={10}>10</option>
                        <option value={30}>30</option>
                    </select>
                </div>
            </div>
            <div className='PieChart' data-testId = 'PieC'>
            <PieChart
                data={colors}
                label={({ dataEntry }) => `${dataEntry.color}: ${dataEntry.value}`}
                labelStyle={{
                    fontSize: '1px',
                    fontFamily: 'sans-serif'
                }}
                labelPosition={40}
                radius={20}
                startAngle={40}
                lengthAngle={360}
                paddingAngle={0}

            ></PieChart>
            
            </div>

        </div>
        
        </div>
    </main>
}
export default BirdPage;
