import { StrictMode } from 'react'
import { createRoot } from 'react-dom/client'
import './index.css'
import App from './App.jsx'

const date = new Date();
const today =date.getDate() +" / "+ date.getMonth() +" / "+ date.getFullYear();
createRoot(document.getElementById('root')).render(
  <StrictMode>
    {/* <App /> */}
    <div className='m-3 ' >
      <p className='font-medium m-3 shadow tracking-wider ' >
        Lorem ipsum dolor sit amet, consectetur adipisicing elit. Mollitia quo omnis temporibus. Atque ex impedit id quo voluptatem natus ipsa.
      </p>
      <p className='font-medium m-3 shadow text-shadow-2xs' >
        Lorem ipsum dolor, sit amet consectetur adipisicing elit. Itaque ipsum neque esse pariatur saepe beatae quam, dignissimos quo magni et. Molestias impedit veritatis et nemo similique commodi. Maxime nesciunt ipsam nemo vitae odio molestias asperiores beatae, consectetur officiis dolores ex, eaque laboriosam velit, eligendi aliquam. Debitis ipsum quidem voluptate illo!
      </p>
      <p className='text-3xl font-bold tracking-wide text-shadow-2xs text-shadow-amber-700 '>
        Mohammed Alhassan
      </p>
      <p className='iterlic font-mono' >
        copy right
      </p>
      <p className='font-mono' >
        { today }
      </p>
    </div>
  </StrictMode>,
)
