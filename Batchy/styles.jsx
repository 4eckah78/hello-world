/* eslint-disable @typescript-eslint/explicit-function-return-type */
import styled from 'styled-components';
import { Link } from 'react-router-dom';
import { StyledIcon } from 'UI/Icon/styles';

export const StyledNavbar = styled.div`
  position: fixed;
  left: 0;
  right: 0;
  width: auto;
  height: 50px;
  background: ${props => props.theme.colors.c_Accent};
  display: flex;
  justify-content: space-between;
  align-items: center;
  padding: 0 ${props => props.theme.offsets.sm};
  margin: 16px;
  flex-flow: row nowrap;
  text-align: left;
  box-shadow: 0 1px 15px rgba(0, 0, 0, 0.25);
  border-radius: 8px 8px 8px 8px;
`;

export const StyledLink = styled(Link)`
  width: 32px;
  display: flex;
  justify-content: center;
  height: 32px;
  margin-left: 4px;
  align-items: center;
  background: ${props => (props.isCurrent ? props.theme.colors.c_Primary : props.theme.colors.c_Accent)};
  cursor: pointer;
  pointer-events: ${props => (props.isCurrent ? 'none' : 'initial')};
  border-radius: 100%;
  transition: background 0.2s ease;

  &:hover {
    background: ${props => props.theme.colors.c_Primary_hover};
  }
  &:active {
    background: ${props => props.theme.colors.c_Primary_focus};
  }

  // All StyledIcon (aka Icon) components inside StyledLink will have these styles
  ${StyledIcon} {
    fill: ${props => (props.isCurrent ? props.theme.colors.c_Accent : props.theme.colors.c_Primary)};
  }
`;
