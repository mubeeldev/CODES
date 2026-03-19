
function App() {
  function imgf() {
    const image = 'https://picsum.photos/300';
    return (
    <img src={image} alt="" className="rounded-2xl m-2 w-full h-full" />
    )
  }

  const count = 10
  return (
    <>
      <h1  className="text-3xl text-center font-serif font-bold ">Random Image Genaarator </h1>
      <div className="m-3">
          {imgf()};
          <button className="m-3 text-3xl text-center bg-blue-600 px-5 rounded-2xl text-white py-2 font-bold  " disabled onClick={imgf} >................</button>
          

      </div>

    </>
  )
}

export default App
