/* eslint-disable @typescript-eslint/explicit-function-return-type */
import React from 'react';
import Typography from 'UI/Typography/Typography';
import { Batches, Tasks } from 'UI/Icons/Icons';
import Icon from 'UI/Icon/Icon';
import { StyledNavbar, StyledLink } from './styles';

const Navbar = () => {
  return (
    <StyledNavbar>
      <Typography variant="h1" fontSize="28px" fontFamily="regular" font-style="normal" color="t_Secondary">
        Батчи
      </Typography>
      <div style={{ display: 'flex' }}>
        <StyledLink isCurrent to="/test">
          <Icon src={<Batches />} />
        </StyledLink>
        <StyledLink to="/test">
          <Icon src={<Tasks />} />
        </StyledLink>
      </div>
    </StyledNavbar>
  );
};

export default Navbar;
