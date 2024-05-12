import './App.css';
import { React, useEffect } from 'react';
import { Routes,Route } from 'react-router-dom';
import BirdPage from './pages/BirdPage.js';
import ViewBirdPage from './pages/ViewBirdPage.js';
import { useState } from 'react';

import {get_birds_paginated, get_birds_count } from './services/bird_service';


const App = () => {

  let [birds, setBirds] = useState([

  ]);
  let [totalCountNush, setTotalCount] = useState(1);

  useEffect(() => {
    const fetchBirdData = async () => {
      try {
        const data = await get_birds_paginated(1, 7);
        const tottemp = await get_birds_count();
        setTotalCount(tottemp.count);
        setBirds(data);
      } catch (error) {
        console.error('Error fetching data:', error);
      }
    };

    fetchBirdData();
  }, []);

  return (
    <>
      <Routes>
        <Route path="/" element={<BirdPage birds= {birds} setBirds= {setBirds} totalCount={totalCountNush} />} />
        <Route path = "/bird/:id" element = {<ViewBirdPage birds= {birds} setBirds= {setBirds} /> }/>
      
      </Routes>
    </>
  );
};

export default App;;

