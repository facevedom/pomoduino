pipeline {
    agent any

    stages {
        stage('Configure Arduino-CLI') {
            steps {
                sh 'arduino-cli config init'
                sh 'arduino-cli core update-index'
                sh 'arduino-cli core install arduino:avr'
            }
        }
        stage('Test') {
            steps {
                echo 'Testing..'
            }
        }
        stage('Deploy') {
            steps {
                echo 'Deploying....'
            }
        }
    }
}