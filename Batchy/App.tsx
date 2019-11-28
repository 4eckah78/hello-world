import * as React from 'react';
import { ThemeProvider } from 'styled-components';
import { Switch, Route } from 'react-router-dom';
import theme from 'Theme/theme';
import HomePage from 'Pages/HomePage/HomePage';
import { LoaderProvider } from 'Common/Loader/LoaderContext';
import { AppStateProvider } from 'Utils/AppState/AppState';
import TasksPage from 'Pages/TasksPage/TasksPage';

const App: React.FunctionComponent = () => {
  return (
    <ThemeProvider theme={theme}>
      <LoaderProvider>
        <AppStateProvider>
          <Switch>
            <Route exact path="/">
              <TasksPage />
            </Route>
          </Switch>
        </AppStateProvider>
      </LoaderProvider>
    </ThemeProvider>
  );
};

export default App;
