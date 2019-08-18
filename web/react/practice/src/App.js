import React from 'react';
import logo from './logo.svg';
import './App.css';
import Counter from './component/Counter';

// Define Component way-1
function App() {
  return (
    <div className="App">
      <header className="App-header">
	  <Counter />
      </header>
    </div>
  );
}

// Define Component way-2
/*
const App = () => {
  return (
    <div className="App">
      <header className="App-header">
	  	<Counter />
      </header>
    </div>
  );
};
*/

// Define Component way-3
/*
class App extends React.Component {
	render() {
		return (
			<div className="App">
				<header className="App-header">
				<Counter />
				</header>
			</div>
		);
	}
}
*/

export default App;
