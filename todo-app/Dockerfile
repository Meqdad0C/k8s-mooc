FROM node:20-alpine

# Set the working directory in the container
WORKDIR /app

# Copy package.json and package-lock.json to the working directory
COPY package*.json ./

ENV NODE_ENV=production

RUN npm install

# Copy the rest of the application code to the working directory
COPY ./src ./src

# Command to run the application
CMD ["npm", "start"]
