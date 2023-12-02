INSERT
  OR IGNORE INTO airplanes(
    id,
    model,
    manufacturer,
    capacity,
    length,
    height,
    speed,
    altitude,
    engine
  )
VALUES
  (
    1,
    'Boeing 737-800',
    'Boeing',
    189,
    39.5,
    12.5,
    839,
    12400,
    'CFM56-7B27'
  ),
  (
    2,
    'Boeing 737-700',
    'Boeing',
    149,
    33.6,
    12.5,
    839,
    12400,
    'CFM56-7B20'
  );

INSERT
  OR IGNORE INTO passengers(
    id,
    name,
    cpf,
    passport,
    birth_date,
    email,
    phone
  )
VALUES
  (
    1,
    'João Sereia',
    '000.000.000-00',
    '0000000000',
    '2002-05-20',
    'joao.sereia@email.com',
    '(047) 99611-8078'
  ),
  (
    2,
    'Guilherme Maffei',
    '111.111.111-11',
    '1111111111',
    '2001-11-09',
    'gui.maffei@email.com',
    '(047) 99138-5663'
  );

INSERT
  OR IGNORE INTO flights(
    id,
    airplane_id,
    departure_date,
    arrival_date,
    departure_address,
    destination_address
  )
VALUES
  (
    1,
    1,
    '2023-12-01 12:00:00',
    '2023-12-20 15:00:00',
    'Joinville - SC',
    'Cascavel - PR'
  ),
  (
    2,
    2,
    '2023-12-01 13:00:00',
    '2023-12-01 16:00:00',
    'Florianópolis - SC',
    'São Paulo - SP'
  );

INSERT
  OR IGNORE INTO tickets(
    id,
    flight_id,
    passenger_id,
    boarding_date,
    boarding_gate,
    seat
  )
VALUES
  (
    1,
    1,
    1,
    '2023-12-01 12:00:00',
    'Y21',
    'A12'
  ),
  (
    2,
    2,
    2,
    '2023-12-01 13:00:00',
    'Y22',
    'A22'
  );

INSERT
  OR IGNORE INTO luggages(
    id,
    ticket_id,
    type,
    description,
    weight
  )
VALUES
  (
    1,
    1,
    'Bagagem de mão',
    'Mala de mão com roupas',
    10.5
  ),
  (
    2,
    1,
    'Bagagem de mão',
    'Mochila com notebook',
    2.5
  ),
  (
    3,
    2,
    'Bagagem de mão',
    'Mala de mão com roupas',
    10.5
  ),
  (
    4,
    2,
    'Bagagem de mão',
    'Mochila com notebook',
    2.5
  );