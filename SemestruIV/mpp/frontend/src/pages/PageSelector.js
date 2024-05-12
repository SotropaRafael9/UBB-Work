import {ChevronLeftIcon, ChevronRightIcon } from '@heroicons/react/20/solid'


const PageSelector = (params) => {
    return <div>
        <div >
            <div className="AlignPage">
            {
                params.offset > 0 && 
                <ChevronLeftIcon className = "ChevronLeft" onClick={() => {params.setOffset(params.offset - 1)}} />
            }
            {
                params.offset < params.totalItems &&
                Array.from(Array(params.size).keys()).map((i) => {
                    return <div key={i} onClick={() => params.setOffset(i)}
                    className={"pages " + (params.offset === i ? "selected" : "")}>
                    {i + 1}
                    </div>
                })
            }
            {
                params.offset < params.totalItems &&
                <ChevronRightIcon className = "ChevronRight" onClick={() => params.setOffset(params.offset + 1)} />
            }
            </div>
        </div>

        

    </div>
}

export default PageSelector;