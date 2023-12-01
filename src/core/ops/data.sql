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
    'John Doe',
    '12345678900',
    '123456789',
    '1990-01-01',
    'john.doe@email.com',
    '00000000000000'
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
    '2020-01-01 00:00:00',
    '2020-01-01 00:00:00',
    'São Paulo',
    'Rio de Janeiro'
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
    '2020-01-01 00:00:00',
    1,
    '1A'
  );