import { render, screen } from '@testing-library/react';
import BirdPage from './BirdPage';
import { BrowserRouter } from 'react-router-dom';
import { fireEvent } from '@testing-library/react';
import { useState } from 'react';
import { PieChart } from 'react-minimal-pie-chart';



test('test for bird page', () => {
    render(
        <BrowserRouter>
            <BirdPage birds = {[
                {id:1, name: "Robin", color: "red", speed: 12.5 },
                {id:2, name: "Sparrow", color: "brown", speed: 15.5 },
                {id:3, name: "Eagle", color: "black", speed: 25.5 },
            ]}
            />
        </BrowserRouter>
    )
    expect(screen.getByText('Robin')).toBeInTheDocument();
    expect(screen.getByText('Sparrow')).toBeInTheDocument();
    expect(screen.getByText('Eagle')).toBeInTheDocument();
    fireEvent.click(screen.getByText('Robin'));
    expect(screen.getByText('Robin')).toBeInTheDocument();
});

function TestOperations()
{
    const bird = {id:1, name: "Robin", color: "red", speed: 12.5 };
    const [birds, setBirds] = useState([bird]);
    
    return(
        <BrowserRouter>
            <BirdPage birds = {birds} setBirds = {setBirds}/>
        </BrowserRouter>)
}

test ('test for add bird', () => {
    render(<TestOperations/>);
    fireEvent.change(screen.getByLabelText('Bird Name:'), {target: {value: 'Sparrow'}});
    fireEvent.change(screen.getByLabelText('Bird Color:'), {target: {value: 'brown'}});
    fireEvent.change(screen.getByLabelText('Bird Speed:'), {target: {value: '15.5'}});
    fireEvent.click(screen.getByText('Add'));
    expect(screen.getByText('Sparrow')).toBeInTheDocument();
}
);

test ('test for update bird', () => {
    render(<TestOperations/>);
    fireEvent.click(screen.getByText('Robin'));
    fireEvent.change(screen.getByLabelText('Bird id:'), {target: {value: '1'}});
    fireEvent.change(screen.getByLabelText('Bird Name:'), {target: {value: 'Sparrow'}});
    fireEvent.change(screen.getByLabelText('Bird Color:'), {target: {value: 'brown'}});
    fireEvent.change(screen.getByLabelText('Bird Speed:'), {target: {value: '15.5'}});
    fireEvent.click(screen.getByText('Update'));
    expect(screen.getByText('Sparrow')).toBeInTheDocument();
});

test ('test for delete bird', () => {
    render(<TestOperations/>);
    fireEvent.click(screen.getByText('Robin'));
    fireEvent.click(screen.getByText('Delete'));
    expect(screen.queryByText('Robin')).toBeNull();
});

test ('test for sort bird', () => {
    render(<TestOperations/>);
    fireEvent.click(screen.getByText('Sort'));
    expect(screen.getByText('Robin')).toBeInTheDocument();
});

test('test for pie chart', () => {
    const birds = [
        { id: 1, name: "Robin", color: "red", speed: 12.5 },
        { id: 2, name: "Sparrow", color: "brown", speed: 15.5 },
        { id: 3, name: "Eagle", color: "black", speed: 25.5 },
    ];

    render(
        <BrowserRouter>
            <BirdPage birds={birds} />
        </BrowserRouter>
    );

    const pieChart = screen.getByTestId('PieC');
    expect(pieChart).toBeInTheDocument();

    fireEvent.click(pieChart);
});

test('test for pagination selector', () => {
    const birds = [
        { id: 1, name: "Robin", color: "red", speed: 12.5 },
        { id: 2, name: "Sparrow", color: "brown", speed: 15.5 },
        { id: 3, name: "Eagle", color: "black", speed: 25.5 },
    ];

    render(
        <BrowserRouter>
            <BirdPage birds={birds} />
        </BrowserRouter>
    );

    const pagination = screen.getByTestId('Paginationn');
    expect(pagination).toBeInTheDocument();

    fireEvent.click(pagination);
});