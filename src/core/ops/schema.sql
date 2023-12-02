CREATE TABLE airplanes (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    model TEXT NOT NULL,
    manufacturer TEXT NOT NULL,
    capacity INTEGER,
    length REAL(10,2),
    height REAL(10,2),
    speed REAL(10,2),
    altitude REAL(10,2),
    engine TEXT
);

CREATE TABLE passengers (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    name TEXT NOT NULL,
    cpf TEXT NOT NULL UNIQUE,
    passport TEXT NOT NULL UNIQUE,
    birth_date DATE NOT NULL,
    email TEXT NOT NULL,
    phone TEXT NOT NULL
);

CREATE TABLE flights (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    airplane_id INTEGER,
    departure_date DATE,
    arrival_date DATE,
    departure_address TEXT,
    destination_address TEXT,
    FOREIGN KEY (airplane_id) REFERENCES airplanes(id)
);

CREATE TABLE tickets (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    flight_id INTEGER,
    passenger_id INTEGER,
    boarding_date DATE,
    boarding_gate TEXT,
    seat TEXT,
    FOREIGN KEY (flight_id) REFERENCES flights(id),
    FOREIGN KEY (passenger_id) REFERENCES passengers(id)
);