pipeline {
    agent {
        node {
            label 'master'
            customWorkspace 'raspiduino/raspiduino/pomoduino/Pomoduino'
        }
    }

    stages {
        stage('Compile') {
            steps {
                sh 'arduino-cli compile --fqbn arduino:avr:uno'
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
