import React from 'react';
import Navbar from 'Common/Navbar/Navbar';
import Typography from 'UI/Typography/Typography';
import Button from 'UI/Button/Button';
import useLoader from 'Common/Loader/useLoader';
import appStorage from 'Utils/AppStorage';
import { useAppDispatch } from 'Utils/AppState/AppState';
import types from 'Utils/AppState/appStateTypes';
import {
  Container,
  Backdrop,
  CardContainer, 
  Controls,
  CurrentCompletedContainer, 
  ButtonContainer,
  CardTop,
  Rectangle4,
  Rectangle5,
} from './styles';

const TasksPage = () => {
  return (
    <Container>
      <Navbar />
      <Backdrop>
        <Controls>
          <CurrentCompletedContainer>
            <Typography variant="h2" fontSize="24px" fontFamily="bold" color="rgba(164, 145, 255, 1)">
              Текущие/
            </Typography>
            <Typography variant="h2" fontSize="24px" fontFamily="bold" color="rgba(164, 145, 255, 0.25)">
              Завершенные
            </Typography>
          </CurrentCompletedContainer>
        </Controls>
        <ButtonContainer>
          <Button>Добавить новую задачу</Button>
        </ButtonContainer>
        <CardContainer>
          <CardTop>
            <Typography variant="h2" fontSize="20px" fontFamily="bold">
              Очень подробная задача
            </Typography>
            Значочки
          </CardTop>
          <Typography variant="p" fontSize="12px" fontFamily="bold">
            Идейные соображения высшего порядка, а также дальнейшее развитие различных форм деятельности обеспечивает
            широкому кругу (специалистов) участие в формировании соответствующий условий активизации
          </Typography>
          <Rectangle4>
            <Typography variant="h3" fontSize="16px" fontFamily="bold">
              Подзадача 1
            </Typography>
            Значочки
          </Rectangle4>
          <Rectangle4>
            <Typography variant="h3" fontSize="16px" fontFamily="bold">
              Подзадача 2
            </Typography>
            Значочки
          </Rectangle4>
          <Rectangle4>
            <Typography variant="h3" fontSize="16px" fontFamily="bold">
              Подзадача 3
            </Typography>
            Значочки
          </Rectangle4>
          <Rectangle4>
            <Typography variant="h3" fontSize="16px" fontFamily="bold" color="rgba(0, 0, 0, 0.5)">
              Новая подзадача
            </Typography>
            +
          </Rectangle4>
          <div style={{ display: 'flex', width: '195px', 'justify-content': 'space-between' }}>
            <Rectangle5>
              Дата
              <div>П</div>
            </Rectangle5>
            <Rectangle5 style={{ width: '80px' }}>
              Батч
              <div>П</div>
            </Rectangle5>
          </div>
        </CardContainer>
        <CardContainer>
          <CardTop>
            <Typography variant="h2" fontSize="20px" fontFamily="bold">
              Не очень подробная задача
            </Typography>
            Значочки
          </CardTop>
          <div style={{ display: 'flex', width: '195px', 'justify-content': 'space-between' }}>
            <Rectangle5>
              Дата
              <div>П</div>
            </Rectangle5>
            <Rectangle5 style={{ width: '80px' }}>
              Батч
              <div>П</div>
            </Rectangle5>
          </div>
        </CardContainer>
      </Backdrop>
    </Container>
  );
};

export default TasksPage;
