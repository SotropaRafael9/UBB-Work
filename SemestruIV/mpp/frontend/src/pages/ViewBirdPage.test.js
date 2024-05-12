import React from 'react';
import { render, screen } from '@testing-library/react';
import { BrowserRouter } from 'react-router-dom';
import ViewBirdPage from './ViewBirdPage';


test('test for view bird page', () => {
    render(
        <BrowserRouter>
            <ViewBirdPage id = {1} birds = {[{id:1, name: "Robin", color: "red", speed: 12.5 }]}/>
        </BrowserRouter>
    )
    expect(screen.getAllByText('Robin')) != null;
    expect(screen.getByText('red')).toBeInTheDocument();
    expect(screen.getByText('12.5')).toBeInTheDocument();
});
