import styled from 'styled-components';

export const Container = styled.div`
  position: absolute;
  width: 100vw;
  height: 100vh;
  display: flex;
  flex-direction: column;
  align-items: center;
  background: #faf6ff;
`;

export const Backdrop = styled.div`
  width: 536px;
  height: 100vh;
  display: flex;
  flex-direction: column;
  align-items: center;
  margin: 85px 0px 32px 0px;
  border-radius: 8px;
  box-shadow: 0px 0px 25px rgba(0, 0, 0, 0.25);
  background: #ffffff;
`;

export const CardContainer = styled.div`
  width: 504px;
  height: auto;

  margin: 18px 16px 0px 16px;
  background: yellow; //#faf6ff;
  box-shadow: 0px 0px 10px rgba(0, 0, 0, 0.1);
  border-radius: 8px;
  padding: 11px 16px 19px 16px;
`;

export const Controls = styled.div`
  position: sticky;
  width: 504px;
  height: 34px;
  display: flex;
  justify-content: center;
  margin: 9px 16px 12px 16px;
  background: magenta;
`;

export const CurrentCompletedContainer = styled.div`
  width: 298px;
  height: 34px;
  display: flex;
  justify-content: center;
  align-items: center;
`;

export const ButtonContainer = styled.div`
  width: 504px;
  height: auto;
  display: flex;
  justify-content: center;
  background: blue; //#fcf9ff;
  border: 2px solid #a491ff;
  box-sizing: border-box;
  border-radius: 5px;
`;

export const CardTop = styled.div`
  width: 472px;
  height: 28.27px;
  margin: 0px 0px 8px 0px;
  padding: 0px 6px 0px 0px;
  display: flex;
  justify-content: space-between;
  align-items: center;
  background: green;
`;

export const Rectangle4 = styled.div`
  width: 472px;
  height: 36px;
  margin: 8px 0px 8px 0px;
  padding: 7px;
  display: flex;
  justify-content: space-between;
  align-items: center;
  box-shadow: 0px 0px 10px rgba(0, 0, 0, 0.1);
  border-radius: 8px;
  background: green;
`;

export const Rectangle5 = styled.div`
  width: 105px;
  height: 28px;
  padding: 3px 8px 3px 8px;
  display: flex;
  justify-content: space-between;
  align-items: center;
  box-shadow: 0px 0px 10px rgba(0, 0, 0, 0.1);
  border-radius: 15px;
  background: green;
`;