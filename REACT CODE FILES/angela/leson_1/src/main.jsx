import { StrictMode } from 'react'
import { createRoot } from 'react-dom/client'
import './index.css'
import App from './App.jsx'

createRoot(document.getElementById('root')).render(
  <StrictMode >
    {/* <App /> */}
    <div className='pl-2'>
      <h2 className='font-bold text-4xl text-amber-50 text-shadow-2xs text-shadow-black ' >My Favourite Food</h2>
      <ul className='list-disc font-bold text-2xl pl-5 text-amber-100 text-shadow-2xs text-shadow-amber-950' >
        <li>Buryani</li>
        <li>Borger</li>
        <li>Sushi</li>
      </ul>
    </div>
  </StrictMode>,
)
